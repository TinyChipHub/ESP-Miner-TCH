#include <string.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "global_state.h"
#include "math.h"
#include "mining.h"
#include "nvs_config.h"
#include "serial.h"
#include "TPS546.h"
#include "vcore.h"
#include "EMC2302.h"
#include "TMP1075.h"

#define GPIO_ASIC_ENABLE CONFIG_GPIO_ASIC_ENABLE
#define GPIO_ASIC_RESET  CONFIG_GPIO_ASIC_RESET
#define GPIO_PLUG_SENSE  CONFIG_GPIO_PLUG_SENSE

#define POLL_RATE 2000
#define MAX_TEMP 90.0
#define THROTTLE_TEMP 75.0
#define THROTTLE_TEMP_RANGE (MAX_TEMP - THROTTLE_TEMP)

#define VOLTAGE_START_THROTTLE 4900
#define VOLTAGE_MIN_THROTTLE 3500
#define VOLTAGE_RANGE (VOLTAGE_START_THROTTLE - VOLTAGE_MIN_THROTTLE)

#define TPS546_THROTTLE_TEMP 105.0
#define TPS546_MAX_TEMP 135.0

#define BOARD_MAX_TEMP 90.0

#define ZYBER_POWER_OFFSET 16

static const char * TAG = "power_management";

// static float _fbound(float value, float lower_bound, float upper_bound)
// {
//     if (value < lower_bound)
//         return lower_bound;
//     if (value > upper_bound)
//         return upper_bound;

//     return value;
// }

// Set the fan speed between 20% min and 100% max based on chip temperature as input.
// The fan speed increases from 20% to 100% proportionally to the temperature increase from 50 and THROTTLE_TEMP
    static double automatic_fan_speed(float chip_temp, GlobalState * GLOBAL_STATE)
{
    double result = 0.0;
    double min_temp = 45.0;
    double min_fan_speed = 35.0;

    if (chip_temp < min_temp) {
        result = min_fan_speed;
    } else if (chip_temp >= THROTTLE_TEMP) {
        result = 100;
    } else {
        double temp_range = THROTTLE_TEMP - min_temp;
        double fan_range = 100 - min_fan_speed;
        result = ((chip_temp - min_temp) / temp_range) * fan_range + min_fan_speed;
    }

    float perc = (float) result / 100;

    switch (GLOBAL_STATE->device_model) {
        case DEVICE_ZYBER8S:
        case DEVICE_ZYBER8G:
            EMC2302_set_fan_speed(0,perc);
            EMC2302_set_fan_speed(1,perc);
            break;
        default:
    }
	return result;
}

void POWER_MANAGEMENT_task(void * pvParameters)
{
    ESP_LOGI(TAG, "Starting");

    GlobalState * GLOBAL_STATE = (GlobalState *) pvParameters;

    PowerManagementModule * power_management = &GLOBAL_STATE->POWER_MANAGEMENT_MODULE;

    power_management->frequency_multiplier = 1;

    power_management->HAS_POWER_EN = GLOBAL_STATE->board_version == 202 || GLOBAL_STATE->board_version == 203 || GLOBAL_STATE->board_version == 204;
    power_management->HAS_PLUG_SENSE = GLOBAL_STATE->board_version == 204;

    //int last_frequency_increase = 0;
    //uint16_t frequency_target = nvs_config_get_u16(NVS_CONFIG_ASIC_FREQ, CONFIG_ASIC_FREQUENCY);

    switch (GLOBAL_STATE->device_model) {
        case DEVICE_ZYBER8S:
        case DEVICE_ZYBER8G:
            TMP1075_init();
            EMC2302_init(true);
            break;
        default:
    }

    vTaskDelay(500 / portTICK_PERIOD_MS);
    uint16_t last_core_voltage = 0.0;
    uint16_t last_asic_frequency = power_management->frequency_value;
    
    while (1) {

        switch (GLOBAL_STATE->device_model) {
            case DEVICE_ZYBER8S:
            case DEVICE_ZYBER8G:
                TPS546_print_status();
                power_management->voltage = TPS546_get_vin() * 1000;
                power_management->current = TPS546_get_iout() * 1000;
                power_management->outVoltage_mv = TPS546_get_vout();
                power_management->power = (TPS546_get_vout() * power_management->current) / 1000 + ZYBER_POWER_OFFSET;
                break;
            default:
        }

        switch (GLOBAL_STATE->device_model) {
            case DEVICE_ZYBER8S:
            case DEVICE_ZYBER8G:
                power_management->chip_temp_avg = (TMP1075_read_temperature(0)+TMP1075_read_temperature(1))/2+5;
				power_management->vr_temp = (float)TPS546_get_temperature();
                // EMC2302 will give bad readings if the ASIC is turned off
                if(power_management->voltage < ZYBER_CONFIG.TPS546_INIT_VOUT_MIN){
                    break;
                }
                // Need to fix for SUPRAHEX which read the actual ASIC temp.
                if ((power_management->vr_temp > TPS546_MAX_TEMP || power_management->chip_temp_avg > BOARD_MAX_TEMP) &&
                    (power_management->frequency_value > 50 || power_management->voltage > 1000)) {
                    ESP_LOGE(TAG, "OVERHEAT  VR: %fC ASIC %fC", power_management->vr_temp, power_management->chip_temp_avg );

                    EMC2302_set_fan_speed(0,1);
                    EMC2302_set_fan_speed(1,1);
                    VCORE_set_voltage(0.0, GLOBAL_STATE);
                    nvs_config_set_u16(NVS_CONFIG_ASIC_VOLTAGE, 1000);
                    nvs_config_set_u16(NVS_CONFIG_ASIC_FREQ, 50);
                    nvs_config_set_u16(NVS_CONFIG_FAN_SPEED, 100);
                    nvs_config_set_u16(NVS_CONFIG_AUTO_FAN_SPEED, 0);
                    nvs_config_set_u16(NVS_CONFIG_OVERHEAT_MODE, 1);
                    exit(EXIT_FAILURE);
                }
                break;
            default:
        }


        if (nvs_config_get_u16(NVS_CONFIG_AUTO_FAN_SPEED, 1) == 1) {

            power_management->fan_perc = (float)automatic_fan_speed(power_management->chip_temp_avg, GLOBAL_STATE);

        } else {
            switch (GLOBAL_STATE->device_model) {
                case DEVICE_ZYBER8S:
                case DEVICE_ZYBER8G:
                    float fs = (float) nvs_config_get_u16(NVS_CONFIG_FAN_SPEED, 100);
                    //ESP_LOGI(TAG, "Manual Fan = %.02f", fs);
                    power_management->fan_perc = fs;
                    EMC2302_set_fan_speed(0,(float) fs / 100);
                    EMC2302_set_fan_speed(1,(float) fs / 100);
                    break;
                default:
            }
        }

        // New voltage and frequency adjustment code
        uint16_t core_voltage = nvs_config_get_u16(NVS_CONFIG_ASIC_VOLTAGE, CONFIG_ASIC_VOLTAGE);
        uint16_t asic_frequency = nvs_config_get_u16(NVS_CONFIG_ASIC_FREQ, CONFIG_ASIC_FREQUENCY);

        if (core_voltage != last_core_voltage) {
            ESP_LOGI(TAG, "setting new vcore voltage to %umV", core_voltage);
            VCORE_set_voltage((double) core_voltage / 1000.0, GLOBAL_STATE);
            last_core_voltage = core_voltage;
        }

        if (asic_frequency != last_asic_frequency) {
            ESP_LOGI(TAG, "New ASIC frequency requested: %uMHz (current: %uMHz)", asic_frequency, last_asic_frequency);
            if (do_frequency_transition((float)asic_frequency)) {
                power_management->frequency_value = (float)asic_frequency;
                ESP_LOGI(TAG, "Successfully transitioned to new ASIC frequency: %uMHz", asic_frequency);
            } else {
                ESP_LOGE(TAG, "Failed to transition to new ASIC frequency: %uMHz", asic_frequency);
            }
            last_asic_frequency = asic_frequency;
        }

        // Check for changing of overheat mode
        SystemModule * module = &GLOBAL_STATE->SYSTEM_MODULE;
        uint16_t new_overheat_mode = nvs_config_get_u16(NVS_CONFIG_OVERHEAT_MODE, 0);
        
        if (new_overheat_mode != module->overheat_mode) {
            module->overheat_mode = new_overheat_mode;
            ESP_LOGI(TAG, "Overheat mode updated to: %d", module->overheat_mode);
        }

        vTaskDelay(POLL_RATE / portTICK_PERIOD_MS);
    }
}
