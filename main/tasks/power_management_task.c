#include "EMC2302.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "global_state.h"
#include "math.h"
#include "mining.h"
#include "nvs_config.h"
#include "serial.h"
#include "TMP1075.h"
#include "TPS546.h"
#include "vcore.h"
#include <string.h>
//#include "max6689.h"

#define POLL_RATE 2000

#define BOARD_MAX_TEMP 98.0
#define BOARD_THROTTLE_TEMP 90.0

#define TPS546_THROTTLE_TEMP 115.0
#define TPS546_MAX_TEMP 135.0

#define ZYBER_POWER_OFFSET 15
#define ZYBER_TEMP_OFFSET 5

static const char * TAG = "power_management";


// Set the fan speed between 45% min and 100% max based on chip temperature as input.
// The fan speed increases from 45% to 100% proportionally to the temperature increase from 50 and THROTTLE_TEMP
// For Hex, we take account on the TPS546 temp as well. Fan speed is depends on the higher temp device.
static double automatic_fan_speed(float temp, GlobalState * GLOBAL_STATE)
{
    double result = 0.0;
    double resultTps = 0.0;
    double min_temp = 45.0;
    double min_fan_speed = 45.0;


    if (temp < min_temp) {
        result = min_fan_speed;
    } else if (temp >= BOARD_THROTTLE_TEMP) {
        result = 100;
    } else {
        double temp_range = BOARD_THROTTLE_TEMP - min_temp;
        double fan_range = 100 - min_fan_speed;
        result = ((temp - min_temp) / temp_range) * fan_range + min_fan_speed;
    }

    float perc = (float) result / 100;

    
    GLOBAL_STATE->POWER_MANAGEMENT_MODULE.fan_perc = perc;
    //ESP_LOGI(TAG, "AutoFan speed set to: %f percent", perc*100);
    EMC2302_set_fan_speed(0,perc);
    EMC2302_set_fan_speed(1,perc);
	return result;
}

void POWER_MANAGEMENT_task(void * pvParameters)
{
    GlobalState * GLOBAL_STATE = (GlobalState *) pvParameters;

    PowerManagementModule * power_management = &GLOBAL_STATE->POWER_MANAGEMENT_MODULE;

    power_management->frequency_multiplier = 1;

    //TODO: delete later
    power_management->HAS_POWER_EN = false;
    power_management->HAS_PLUG_SENSE = false;

    uint16_t auto_fan_speed = 1;

    //float power_offset = 0;
    TMP1075_init();
    EMC2302_init(true);

    vTaskDelay(500 / portTICK_PERIOD_MS);

    float targetPwOffset = 0.0f;
    float targetTempOffset = 0.0f;

    switch (GLOBAL_STATE->device_model) {
        case DEVICE_ZYBER_OCTO:
            targetPwOffset = ZYBER_POWER_OFFSET;
            targetTempOffset = ZYBER_TEMP_OFFSET;
            break;
        default:
            break;
    }

    while (1) {
        auto_fan_speed = nvs_config_get_u16(NVS_CONFIG_AUTO_FAN_SPEED, 1);
        TPS546_print_status();
        power_management->voltage = TPS546_get_vin() * 1000;
        power_management->current = TPS546_get_iout() * 1000;
        ESP_LOGI(TAG, "IOut: %.2f", power_management->current);
        power_management->power = (TPS546_get_vout() * power_management->current) / 1000 + targetPwOffset;
        power_management->chip_temp_avg = (TMP1075_read_temperature(0)+TMP1075_read_temperature(1))/2+targetTempOffset;
		power_management->vr_temp = (float)TPS546_get_temperature();

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

        if (auto_fan_speed == 1) {
            power_management->fan_perc = (float)automatic_fan_speed(power_management->chip_temp_avg,GLOBAL_STATE);
        } else {
            uint16_t fs  = (float) nvs_config_get_u16(NVS_CONFIG_FAN_SPEED, 100);
            power_management->fan_perc = fs;
            EMC2302_set_fan_speed(0,(float) fs / 100);
            EMC2302_set_fan_speed(1,(float) fs / 100);
        }

        // Read the state of GPIO12
        if (power_management->HAS_PLUG_SENSE) {
            int gpio12_state = gpio_get_level(GPIO_NUM_12);
            if (gpio12_state == 0) {
                // turn ASIC off
                gpio_set_level(GPIO_NUM_10, 1);
            }
        }

        vTaskDelay(POLL_RATE / portTICK_PERIOD_MS);
    }
}

