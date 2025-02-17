#include <stdio.h>
#include "esp_log.h"
#include "i2c_bitaxe.h"

#include "TMP1075.h"

static const char *TAG = "TMP1075";

static i2c_master_dev_handle_t tmp1075_u7_dev_handle;
static i2c_master_dev_handle_t tmp1075_u8_dev_handle;

/**
 * @brief Initialize the TMP1075 sensor.
 *
 * @return esp_err_t ESP_OK on success, or an error code on failure.
 */
esp_err_t TMP1075_init(void) {
    return i2c_bitaxe_add_device(TMP1075_I2CADDR_U7, &tmp1075_u7_dev_handle, TAG) | 
            i2c_bitaxe_add_device(TMP1075_I2CADDR_U8, &tmp1075_u8_dev_handle, TAG);
}

bool TMP1075_installed(int device_index)
{
    uint8_t data[2];
    esp_err_t result = ESP_FAIL;

    // read the configuration register
    //ESP_LOGI(TAG, "Reading configuration register");
    if(device_index==0){
        result = i2c_bitaxe_register_read(tmp1075_u7_dev_handle, TMP1075_CONFIG_REG, data, 2);
    }else if(device_index==1){
        result = i2c_bitaxe_register_read(tmp1075_u8_dev_handle, TMP1075_CONFIG_REG, data, 2);
    }
    
    //ESP_LOGI(TAG, "Configuration[%d] = %02X %02X", device_index, data[0], data[1]);

    return (result == ESP_OK?true:false);
}

uint8_t TMP1075_read_temperature(int device_index)
{
    uint8_t data[2];

    if(device_index==0){
        ESP_ERROR_CHECK(i2c_bitaxe_register_read(tmp1075_u7_dev_handle, TMP1075_TEMP_REG, data, 2));
    }else if(device_index==1){
        ESP_ERROR_CHECK(i2c_bitaxe_register_read(tmp1075_u8_dev_handle, TMP1075_TEMP_REG, data, 2));
    }
    
    //ESP_LOGI(TAG, "Raw Temperature = %02X %02X", data[0], data[1]);
    //ESP_LOGI(TAG, "Temperature[%d] = %d", device_index, data[0]);
    return data[0];
}

float TMP1075_read_temperature_weighted(){
    return (float)(TMP1075_read_temperature(0)*WEIGHTED_U7+TMP1075_read_temperature(1)*WEIGHTED_U8);
}

