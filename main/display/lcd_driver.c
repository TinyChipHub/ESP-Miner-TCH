#include "driver/gpio.h"
#include "rom/gpio.h"
#include "esp_lcd_io_i80.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "lvgl.h"
#include "esp_log.h"
#include "global_state.h"

#include "lcd_driver.h"

static const char * TAG = "lcd_display";
static esp_lcd_i80_bus_handle_t d_bus_handle = NULL;
static esp_lcd_panel_io_handle_t d_io_handle = NULL;
static esp_lcd_panel_handle_t d_panel_handle = NULL;

esp_err_t init_display(GlobalState * GLOBAL_STATE) {

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
    esp_err_t ret = ESP_OK;

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

    ret = esp_lcd_new_i80_bus(&bus_config, &d_bus_handle);

    if(ret!=ESP_OK){
        return ret;
    }

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

    ret = esp_lcd_new_panel_io_i80(d_bus_handle, &io_config, &d_io_handle);

    if(ret!=ESP_OK){
        return ret;
    }

    ESP_LOGI(TAG, "Install LCD driver of st7789");
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = DISPLAY_PIN_REST,
        .color_space = ESP_LCD_COLOR_SPACE_RGB,
        .bits_per_pixel = 16,
    };

    ret = esp_lcd_new_panel_st7789(d_io_handle, &panel_config, &d_panel_handle);
    if(ret!=ESP_OK){
        return ret;
    }

    esp_lcd_panel_reset(d_panel_handle);
    esp_lcd_panel_init(d_panel_handle);
    esp_lcd_panel_invert_color(d_panel_handle, true);

    esp_lcd_panel_swap_xy(d_panel_handle, true);
    esp_lcd_panel_set_gap(d_panel_handle, 0, 35);
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(d_panel_handle, true));

    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(DISPLAY_PIN_PWR, true);
    gpio_set_level(DISPLAY_PIN_BK_PWR, DISPLAY_LCD_BK_LIGHT_ON);

    ESP_LOGI(TAG, "Initial LCD display with Intel i80 Done! ");
    ESP_LOGI(TAG, ".............................................");
    ESP_LOGI(TAG, "Initialize LVGL library");

    lv_init();
    


    return ret;
}