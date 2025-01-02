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
LV_IMG_DECLARE(img_logoScreen8S);

static const Theme theme_zyber8s={
    .ui_logoBg = &img_logoScreen8S,
};

static const Theme theme_zyber8G;

#endif