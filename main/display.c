#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "driver/gpio.h"
#include "rom/gpio.h"
#include "esp_lcd_io_i80.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"
#include "lvgl.h"
#include "lvgl__lvgl/src/themes/lv_theme_private.h"
#include "esp_lvgl_port.h"
#include "global_state.h"
#include "nvs_config.h"
#include "i2c_bitaxe.h"
#include "display.h"
// #include "driver/i2c_master.h"
// #include "driver/i2c_types.h"
// #include "esp_lcd_panel_ssd1306.h"

static const char * TAG = "display";

static lv_theme_t theme;
static lv_style_t scr_style;

extern const lv_font_t font_XinYin_reg14;

static void theme_apply(lv_theme_t *theme, lv_obj_t *obj) {
    if (lv_obj_get_parent(obj) == NULL) {
        lv_obj_add_style(obj, &scr_style, LV_PART_MAIN);
    }
}

esp_err_t display_init(void * pvParameters){
     GlobalState * GLOBAL_STATE = (GlobalState *) pvParameters;

    uint8_t flip_screen = nvs_config_get_u16(NVS_CONFIG_FLIP_SCREEN, 1);

    ESP_LOGI(TAG, "=============Starting Display Initialization Sequence============");
    ESP_LOGI(TAG, "Turn off LCD backlight");
    gpio_config_t bk_gpio_config = {.pin_bit_mask = 1ULL << DISPLAY_PIN_BK_PWR, .mode = GPIO_MODE_OUTPUT};
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));
    
    gpio_pad_select_gpio(DISPLAY_PIN_BK_PWR);
    gpio_pad_select_gpio(DISPLAY_PIN_RD);
    gpio_pad_select_gpio(DISPLAY_PIN_PWR);

    gpio_set_direction(DISPLAY_PIN_RD, GPIO_MODE_OUTPUT);
    gpio_set_direction(DISPLAY_PIN_BK_PWR, GPIO_MODE_OUTPUT);
    gpio_set_direction(DISPLAY_PIN_PWR, GPIO_MODE_OUTPUT);

    gpio_set_level(DISPLAY_PIN_RD, true);
    gpio_set_level(DISPLAY_PIN_BK_PWR, DISPLAY_LCD_BK_LIGHT_OFF);

    ESP_LOGI(TAG, "Initial LCD display with Intel i80 interface.....");

    ESP_LOGI(TAG, "Creating i80 bus handle");
    esp_lcd_i80_bus_handle_t bus_handle = NULL;
    esp_lcd_i80_bus_config_t bus_config = {
        .clk_src = LCD_CLK_SRC_DEFAULT,
        .dc_gpio_num = DISPLAY_PIN_DC,
        .wr_gpio_num = DISPLAY_PIN_WR,
        .data_gpio_nums = {
            DISPLAY_PIN_DATA0,
            DISPLAY_PIN_DATA1,
            DISPLAY_PIN_DATA2,
            DISPLAY_PIN_DATA3,
            DISPLAY_PIN_DATA4,
            DISPLAY_PIN_DATA5,
            DISPLAY_PIN_DATA6,
            DISPLAY_PIN_DATA7,
        },
        .bus_width = 8,
        .max_transfer_bytes = LVGL_LCD_BUF_SIZE * sizeof(uint16_t), // transfer 100 lines of pixels (assume pixel is RGB565) at most in one transaction
        .psram_trans_align = DISPLAY_PSRAM_TRANS_ALIGN,
        .sram_trans_align = DISPLAY_SRAM_TRANS_ALIGN
    };
    ESP_RETURN_ON_ERROR(esp_lcd_new_i80_bus(&bus_config, &bus_handle),TAG,"Fail to create i80 bus handle");

    ESP_LOGI(TAG, "Creating LCD panel i80 io handle");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = {
        .cs_gpio_num = DISPLAY_PIN_CS,
        .pclk_hz = DISPLAY_PIXEL_CLOCK_HZ,
        .trans_queue_depth = 20,
        //.on_color_trans_done = onLvglFlashReady,
        //.user_ctx = &disp_drv,
        .lcd_cmd_bits = DISPLAY_LCD_CMD_BITS,
        .lcd_param_bits = DISPLAY_LCD_PARAM_BITS,
        .dc_levels =
            {
                .dc_idle_level = 0,
                .dc_cmd_level = 0,
                .dc_dummy_level = 0,
                .dc_data_level = 1,
            }
    };
    ESP_RETURN_ON_ERROR(esp_lcd_new_panel_io_i80(bus_handle, &io_config, &io_handle),TAG,"Fail to create lcd i80 io handle");

    ESP_LOGI(TAG, "Install LCD driver of st7789");
    esp_lcd_panel_handle_t panel_handle = NULL;
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = DISPLAY_PIN_REST,
        .color_space = ESP_LCD_COLOR_SPACE_RGB,
        .bits_per_pixel = 16,
    };

    ESP_RETURN_ON_ERROR(esp_lcd_new_panel_st7789(io_handle,&panel_config, &panel_handle),TAG,"Fail to install LCD driver of st7789");
    
    
    ESP_RETURN_ON_ERROR(esp_lcd_panel_reset(panel_handle), TAG, "Panel reset failed");
    esp_err_t esp_lcd_panel_init_err = esp_lcd_panel_init(panel_handle);
    if (esp_lcd_panel_init_err != ESP_OK) {
        ESP_LOGE(TAG, "Panel init failed, no display connected?");
    }  else {
        ESP_RETURN_ON_ERROR(esp_lcd_panel_invert_color(panel_handle, true), TAG, "Panel invert color failed");
        // ESP_RETURN_ON_ERROR(esp_lcd_panel_mirror(panel_handle, false, false), TAG, "Panel mirror failed");
    }

    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(DISPLAY_PIN_PWR, true);
    gpio_set_level(DISPLAY_PIN_BK_PWR, DISPLAY_LCD_BK_LIGHT_ON);

    ESP_LOGI(TAG, "Initial LCD display with Intel i80 Done! ");
    ESP_LOGI(TAG, ".............................................");
    ESP_LOGI(TAG, "Initializing and porting to LVGL library ");

    const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
    ESP_RETURN_ON_ERROR(lvgl_port_init(&lvgl_cfg), TAG, "LVGL init failed");

    const lvgl_port_display_cfg_t disp_cfg = {
        .io_handle = io_handle,
        .panel_handle = panel_handle,
        .buffer_size = DISPLAY_WIDTH * DISPLAY_HEIGHT,
        .double_buffer = true,
        .hres = DISPLAY_WIDTH,
        .vres = DISPLAY_HEIGHT,
        .monochrome = false,
        .color_format = LV_COLOR_FORMAT_RGB565,
        .rotation = {
            .swap_xy = false,
            .mirror_x = !flip_screen, // The screen is not flipped, this is for backwards compatibility
            .mirror_y = !flip_screen,
        },
        .flags = {
            .swap_bytes = false,
            .sw_rotate = false,
        }
    };

    lv_disp_t * disp = lvgl_port_add_disp(&disp_cfg);
    if (esp_lcd_panel_init_err == ESP_OK) {

        if (lvgl_port_lock(0)) {
            lv_style_init(&scr_style);
            lv_style_set_text_font(&scr_style, &font_XinYin_reg14);
            lv_style_set_bg_opa(&scr_style, LV_OPA_COVER);

            lv_theme_set_apply_cb(&theme, theme_apply);

            lv_display_set_theme(disp, &theme);
            lvgl_port_unlock();
        }

        // Only turn on the screen when it has been cleared
        ESP_RETURN_ON_ERROR(esp_lcd_panel_disp_on_off(panel_handle, true), TAG, "Panel display on failed");   

        GLOBAL_STATE->SYSTEM_MODULE.is_screen_active = true;
    } else {
        ESP_LOGW(TAG, "No display found.");
    }

    return ESP_OK;
}

// esp_err_t display_init(void * pvParameters)
// {
//     GlobalState * GLOBAL_STATE = (GlobalState *) pvParameters;

//     uint8_t flip_screen = nvs_config_get_u16(NVS_CONFIG_FLIP_SCREEN, 1);
//     uint8_t invert_screen = nvs_config_get_u16(NVS_CONFIG_INVERT_SCREEN, 0);

//     i2c_master_bus_handle_t i2c_master_bus_handle;
//     ESP_RETURN_ON_ERROR(i2c_bitaxe_get_master_bus_handle(&i2c_master_bus_handle), TAG, "Failed to get i2c master bus handle");

//     ESP_LOGI(TAG, "Install panel IO");
//     esp_lcd_panel_io_handle_t io_handle = NULL;
//     esp_lcd_panel_io_i2c_config_t io_config = {
//         .scl_speed_hz = I2C_BUS_SPEED_HZ,
//         .dev_addr = SSD1306_I2C_ADDRESS,
//         .control_phase_bytes = 1,
//         .lcd_cmd_bits = LCD_CMD_BITS,
//         .lcd_param_bits = LCD_PARAM_BITS,
//         .dc_bit_offset = 6                     
//     };
    
//     ESP_RETURN_ON_ERROR(esp_lcd_new_panel_io_i2c(i2c_master_bus_handle, &io_config, &io_handle), TAG, "Failed to initialise i2c panel bus");

//     ESP_LOGI(TAG, "Install SSD1306 panel driver");
//     esp_lcd_panel_handle_t panel_handle = NULL;
//     esp_lcd_panel_dev_config_t panel_config = {
//         .bits_per_pixel = 1,
//         .reset_gpio_num = -1,
//     };

//     esp_lcd_panel_ssd1306_config_t ssd1306_config = {
//         .height = LCD_V_RES,
//     };
//     panel_config.vendor_config = &ssd1306_config;

//     ESP_RETURN_ON_ERROR(esp_lcd_new_panel_ssd1306(io_handle, &panel_config, &panel_handle), TAG, "No display found");
//     ESP_RETURN_ON_ERROR(esp_lcd_panel_reset(panel_handle), TAG, "Panel reset failed");
//     esp_err_t esp_lcd_panel_init_err = esp_lcd_panel_init(panel_handle);
//     if (esp_lcd_panel_init_err != ESP_OK) {
//         ESP_LOGE(TAG, "Panel init failed, no display connected?");
//     }  else {
//         ESP_RETURN_ON_ERROR(esp_lcd_panel_invert_color(panel_handle, invert_screen), TAG, "Panel invert failed");
//         // ESP_RETURN_ON_ERROR(esp_lcd_panel_mirror(panel_handle, false, false), TAG, "Panel mirror failed");
//     }
    
//     ESP_LOGI(TAG, "Initialize LVGL");

//     const lvgl_port_cfg_t lvgl_cfg = ESP_LVGL_PORT_INIT_CONFIG();
//     ESP_RETURN_ON_ERROR(lvgl_port_init(&lvgl_cfg), TAG, "LVGL init failed");

//     const lvgl_port_display_cfg_t disp_cfg = {
//         .io_handle = io_handle,
//         .panel_handle = panel_handle,
//         .buffer_size = LCD_H_RES * LCD_V_RES,
//         .double_buffer = true,
//         .hres = LCD_H_RES,
//         .vres = LCD_V_RES,
//         .monochrome = true,
//         .color_format = LV_COLOR_FORMAT_RGB565,
//         .rotation = {
//             .swap_xy = false,
//             .mirror_x = !flip_screen, // The screen is not flipped, this is for backwards compatibility
//             .mirror_y = !flip_screen,
//         },
//         .flags = {
//             .swap_bytes = false,
//             .sw_rotate = false,
//         }
//     };

//     lv_disp_t * disp = lvgl_port_add_disp(&disp_cfg);

//     if (esp_lcd_panel_init_err == ESP_OK) {

//         if (lvgl_port_lock(0)) {
//             lv_style_init(&scr_style);
//             lv_style_set_text_font(&scr_style, &font_XinYin_reg14);
//             lv_style_set_bg_opa(&scr_style, LV_OPA_COVER);

//             lv_theme_set_apply_cb(&theme, theme_apply);

//             lv_display_set_theme(disp, &theme);
//             lvgl_port_unlock();
//         }

//         // Only turn on the screen when it has been cleared
//         ESP_RETURN_ON_ERROR(esp_lcd_panel_disp_on_off(panel_handle, true), TAG, "Panel display on failed");   

//         GLOBAL_STATE->SYSTEM_MODULE.is_screen_active = true;
//     } else {
//         ESP_LOGW(TAG, "No display found.");
//     }

//     return ESP_OK;
// }
