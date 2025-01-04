#ifndef THEMES_H_
#define THEMES_H_

#include "lvgl.h"

typedef struct 
{
    lv_img_dsc_t *ui_logoBg;
    lv_img_dsc_t *ui_setupBg;
    lv_img_dsc_t *ui_miningStatBg;
    lv_img_dsc_t *ui_deviceInfoBg;
    lv_img_dsc_t *ui_networkBg;
    lv_img_dsc_t *ui_overheatBg;

} Theme;

// image files for theme Zyber8S
LV_IMG_DECLARE(img_logo_screen_8s);
LV_IMG_DECLARE(img_setup_screen_8s);
LV_IMG_DECLARE(img_mining_screen_8s);
LV_IMG_DECLARE(img_device_screen_8s);
LV_IMG_DECLARE(img_network_screen_8s);
LV_IMG_DECLARE(img_overheat_screen_8s);

static Theme theme_zyber8s={
    .ui_logoBg = &img_logo_screen_8s,
    .ui_setupBg = &img_setup_screen_8s,
    .ui_miningStatBg = &img_mining_screen_8s,
    .ui_deviceInfoBg = &img_device_screen_8s,
    .ui_networkBg = &img_network_screen_8s,
    .ui_overheatBg = &img_overheat_screen_8s
};

static Theme theme_zyber8G;

#endif