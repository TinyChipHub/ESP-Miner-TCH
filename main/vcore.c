#include <stdio.h>
#include <math.h>
#include "esp_log.h"

#include "vcore.h"
#include "adc.h"
#include "TPS546.h"

static const char *TAG = "vcore.c";

uint8_t VCORE_init(GlobalState * global_state) {
    uint8_t result=-1;
    if(global_state->device_model == DEVICE_ZYBER_8G||
        global_state->device_model == DEVICE_ZYBER_8S){
        return TPS546_init(ZYBER_CONFIG);
    }
    return result;
}


bool VCORE_set_voltage(float core_voltage, GlobalState * global_state)
{
    switch (global_state->device_model) {
            case DEVICE_ZYBER_8S:
            case DEVICE_ZYBER_8G:
            ESP_LOGI(TAG, "Set ASIC voltage = %.3fV", core_voltage);
            TPS546_set_vout(core_voltage * (float)global_state->voltage_domain);
        break;
        default:
    }

    return true;
}

uint16_t VCORE_get_voltage_mv(GlobalState * global_state) {

    switch (global_state->device_model) {
        case DEVICE_ZYBER_8S:
        case DEVICE_ZYBER_8G:
            return (TPS546_get_vout() * 1000) / global_state->voltage_domain;
            break;
        default:
    }

    return ADC_get_vcore() / global_state->voltage_domain;
}
