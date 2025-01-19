#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "global_state.h"

#include "../display/lcd_driver.h"
#include "../display/ui.h"
#include "display_task.h"

static bool d_isAnimateEnable = false;
static const char *TAG = "display_task";


#define DISPLAY_LVGL_TICK_PERIOD_MS 30        //s
#define DISPLAY_CHANGE_INTERVAL 10 //s

void change_screen(GlobalState *GLOBAL_STATE){
    if(GLOBAL_STATE->displayState==D_MINING_INFO){
        d_isAnimateEnable=true;
        if(GLOBAL_STATE->ui.ui_deviceInfoScreen==NULL){
            initDeviceInfoScreen(&(GLOBAL_STATE->ui));
        }
        ui_screen_change(GLOBAL_STATE->ui.ui_deviceInfoScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        GLOBAL_STATE->displayState=D_DEVICE_INFO;
        ESP_LOGI(TAG, "Device info screen displayed");
    }else if(GLOBAL_STATE->displayState==D_DEVICE_INFO){
        d_isAnimateEnable=true;
        if(GLOBAL_STATE->ui.ui_networkScreen==NULL){
            initNetworkScreen(&(GLOBAL_STATE->ui));
        }
        ui_screen_change(GLOBAL_STATE->ui.ui_networkScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        GLOBAL_STATE->displayState=D_NETWORK_INFO;
        ESP_LOGI(TAG, "Network info screen displayed");
    }else if(GLOBAL_STATE->displayState==D_NETWORK_INFO){
        d_isAnimateEnable=true;
        ui_screen_change(GLOBAL_STATE->ui.ui_miningStatScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        GLOBAL_STATE->displayState=D_MINING_INFO;
        ESP_LOGI(TAG, "Mining info screen displayed");
    }else if(GLOBAL_STATE->displayState==D_LOGO){
        if(GLOBAL_STATE->wifi_connected){
            d_isAnimateEnable=true;
            if(GLOBAL_STATE->ui.ui_miningStatScreen==NULL){
                initMiningStatScreen(&(GLOBAL_STATE->ui));
            }
            ui_screen_change(GLOBAL_STATE->ui.ui_miningStatScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            GLOBAL_STATE->displayState=D_MINING_INFO;
            ESP_LOGI(TAG, "Mining info screen displayed");
            if(GLOBAL_STATE->ui.ui_setupScreen){
                lv_obj_clean(GLOBAL_STATE->ui.ui_setupScreen);
                GLOBAL_STATE->ui.ui_setupScreen=NULL;
            }
        }else{
            d_isAnimateEnable=true;
            initSetupScreen(&(GLOBAL_STATE->ui));
            ui_screen_change(GLOBAL_STATE->ui.ui_setupScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            GLOBAL_STATE->displayState=D_SETUP_INFO;
            ESP_LOGI(TAG, "Setup info screen displayed");
            if(GLOBAL_STATE->ui.ui_logoScreen){
                lv_obj_clean(GLOBAL_STATE->ui.ui_logoScreen);
                GLOBAL_STATE->ui.ui_logoScreen=NULL;
            }
        }
    }
}

void display_task(void * pvParameters){
    GlobalState * GLOBAL_STATE = (GlobalState *) pvParameters;

    int32_t elapsed_Ani_cycles = 0;
    uint64_t lastChangeScreenTime = 0;

    while(1){
        uint64_t currentTime = esp_timer_get_time();
        // Enabled when change screen animation is activated
        if (d_isAnimateEnable) {
            lv_tick_inc(DISPLAY_LVGL_TICK_PERIOD_MS);
            lv_timer_handler();                 // Process pending LVGL tasks
            vTaskDelay(5 / portTICK_PERIOD_MS); // Delay during animations
            if (elapsed_Ani_cycles++ > 80) {
                // After 1s aprox stop animations
                d_isAnimateEnable = false;
                GLOBAL_STATE->isScreenChanging=false;
                elapsed_Ani_cycles = 0;
            }
        } else {
            if (GLOBAL_STATE->isDBtnShortPressed) {
                GLOBAL_STATE->isScreenChanging=true;
                GLOBAL_STATE->isDBtnShortPressed = false;
                if (!GLOBAL_STATE->isScreenOn)
                    toggleScreenOnOff(GLOBAL_STATE, true);
                change_screen(GLOBAL_STATE);
            }
            vTaskDelay(200 / portTICK_PERIOD_MS); // Delay waiting animation trigger
        }

        if(GLOBAL_STATE->displayState==D_READY){
            GLOBAL_STATE->displayState=D_LOGO;

            d_isAnimateEnable=true;
            if(GLOBAL_STATE->ui.ui_logoScreen==NULL){
                initLogoScreen(&(GLOBAL_STATE->ui));
            }
            ui_screen_change(GLOBAL_STATE->ui.ui_logoScreen, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0);
            lastChangeScreenTime = esp_timer_get_time();
        }else{
            if((currentTime-lastChangeScreenTime)/1000>10000){
                //ESP_LOGI(TAG, "Here is a big int %" PRId64 "\n");
                lastChangeScreenTime = currentTime;
                change_screen(GLOBAL_STATE);
            }
        }

        
           
    }
}