#include <stdio.h>
#include <math.h>
#include "esp_log.h"

#include "vcore.h"
#include "adc.h"
#include "TPS546.h"

#define TPS40305_VFB 0.6

// DS4432U Transfer function constants for Bitaxe board
// #define BITAXE_RFS 80000.0     // R16
// #define BITAXE_IFS ((DS4432_VRFS * 127.0) / (BITAXE_RFS * 16))
#define BITAXE_IFS 0.000098921 // (Vrfs / Rfs) x (127/16)  -> Vrfs = 0.997, Rfs = 80000
#define BITAXE_RA 4750.0       // R14
#define BITAXE_RB 3320.0       // R15
#define BITAXE_VNOM 1.451   // this is with the current DAC set to 0. Should be pretty close to (VFB*(RA+RB))/RB
#define BITAXE_VMAX 2.39
#define BITAXE_VMIN 0.046

static const char *TAG = "vcore.c";

esp_err_t VCORE_init(GlobalState * global_state) {
    switch (global_state->device_model) {
        case DEVICE_ZYBER8S:
        case DEVICE_ZYBER8G:
            if (TPS546_init(ZYBER_CONFIG) != ESP_OK) {
                ESP_LOGE(TAG, "TPS546 init failed!");
                return ESP_FAIL;
            }
            break;
        default:
    }
    return ESP_OK;
}

esp_err_t VCORE_set_voltage(float core_voltage, GlobalState * global_state)
{
    switch (global_state->device_model) {
        case DEVICE_ZYBER8S:
        case DEVICE_ZYBER8G:
            ESP_LOGI(TAG, "Set ASIC voltage = %.3fV", core_voltage);
            TPS546_set_vout(core_voltage * (float)global_state->voltage_domain);
        default:
    }

    return ESP_OK;
}

uint16_t VCORE_get_voltage_mv(GlobalState * global_state) {
    switch (global_state->device_model) {
        case DEVICE_ZYBER8S:
        case DEVICE_ZYBER8G:
            return (TPS546_get_vout() * 1000) / global_state->voltage_domain;
            break;
        default:
    }
    return 0;
}
