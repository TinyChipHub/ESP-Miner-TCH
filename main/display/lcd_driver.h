#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "driver/gpio.h"
#include "esp_lcd_io_i80.h"
#include "global_state.h"

//LCD data lines
#define DISPLAY_PIN_DATA0 (gpio_num_t) 12
#define DISPLAY_PIN_DATA1 (gpio_num_t) 14
#define DISPLAY_PIN_DATA2 (gpio_num_t) 15
#define DISPLAY_PIN_DATA3 (gpio_num_t) 16
#define DISPLAY_PIN_DATA4 (gpio_num_t) 35
#define DISPLAY_PIN_DATA5 (gpio_num_t) 36
#define DISPLAY_PIN_DATA6 (gpio_num_t) 37
#define DISPLAY_PIN_DATA7 (gpio_num_t) 38

//LCD control pins
#define DISPLAY_PIN_REST (gpio_num_t) 6
#define DISPLAY_PIN_CS (gpio_num_t) 7
#define DISPLAY_PIN_DC (gpio_num_t) 8
#define DISPLAY_PIN_WR (gpio_num_t) 9
#define DISPLAY_PIN_RD (gpio_num_t) 10

//LCD Power Control
#define DISPLAY_PIN_PWR (gpio_num_t) 41
#define DISPLAY_PIN_BK_PWR (gpio_num_t) 40
#define DISPLAY_LCD_BK_LIGHT_ON 1
#define DISPLAY_LCD_BK_LIGHT_OFF !DISPLAY_LCD_BK_LIGHT_ON

#define DISPLAY_WIDTH 320
#define DISPLAY_HEIGHT 170
#define LVGL_LCD_BUF_SIZE (DISPLAY_WIDTH * DISPLAY_HEIGHT) / 4

// Alignment settings for PSRAM and SRAM transfers
#define DISPLAY_PSRAM_TRANS_ALIGN 64                  // Alignment for PSRAM transfers
#define DISPLAY_SRAM_TRANS_ALIGN 4                    // Alignment for SRAM transfers
#define DISPLAY_PIXEL_CLOCK_HZ (6528000)              // Pixel clock for LCD in Hz (60 FPS, 170 x 320 pixels)

// Bit sizes for LCD commands and parameters
#define DISPLAY_LCD_CMD_BITS 8                 // Bits for LCD commands
#define DISPLAY_LCD_PARAM_BITS 8               // Bits for LCD parameters


esp_err_t init_display(GlobalState * GLOBAL_STATE);
bool onLvglFlashReady(esp_lcd_panel_io_handle_t panelIo, esp_lcd_panel_io_event_data_t* edata, void* userCtx);
void lvglFlushCallback(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* colorMap);
void toggleScreenOnOff(GlobalState * , bool);


#endif