#ifndef UI_H_
#define UI_H_

#include "lvgl.h"
#include "themes/themes.h"

#define LV_FONT_CUSTOM_DECLARE
LV_FONT_DECLARE(font_XinYin_reg13);
LV_FONT_DECLARE(font_XinYin_reg14);
LV_FONT_DECLARE(font_XinYin_reg24);
LV_FONT_DECLARE(font_XinYin_reg45);


typedef struct
{
    lv_obj_t *ui_logoScreen;
    lv_obj_t *ui_logoBgImg;
    lv_obj_t *ui_lbLogoVersion;
    
    lv_obj_t *ui_setupScreen;
    lv_obj_t *ui_setupBgImg;
    lv_obj_t *ui_lbSetupSSID;
    lv_obj_t *ui_lbSetupIP;

    lv_obj_t *ui_miningStatScreen;
    lv_obj_t *ui_miningStatBgImg;
    lv_obj_t *ui_lbMiningHashrate;
    lv_obj_t *ui_lbMiningTarget;
    lv_obj_t *ui_lbMiningBD;
    lv_obj_t *ui_lbMiningAR;
    lv_obj_t *ui_lbBlockFound;

    lv_obj_t *ui_deviceInfoScreen;
    lv_obj_t *ui_deviceInfoBgImg;
    lv_obj_t *ui_lbDIChips;
    lv_obj_t *ui_lbDIVin;
    lv_obj_t *ui_lbDIVout;
    lv_obj_t *ui_lbDIPwr;
    lv_obj_t *ui_lbDIFanPerc;
    lv_obj_t *ui_lbDITemp;

    lv_obj_t *ui_networkScreen;
    lv_obj_t *ui_networkBgImg;
    lv_obj_t *ui_lbNWSSID;
    lv_obj_t *ui_lbNWIP;
    lv_obj_t *ui_lbNWMAC;
    lv_obj_t *ui_lbNWPool;
    lv_obj_t *ui_lbNWAddr;
    
    lv_obj_t *ui_overheatScreen;
    lv_obj_t *ui_overheatBgImg;
    lv_obj_t *ui_lbOHIP;

    Theme theme;
} UI;

lv_obj_t * createDefalutLabel(lv_obj_t *parent, const char* text);
lv_obj_t * createDefalutImage(lv_obj_t *parent, const void* src);

void initLogoScreen(UI *ui);
void initSetupScreen(UI *ui);
void initMiningStatScreen(UI *ui);
void initDeviceInfoScreen(UI *ui);
void initNetworkScreen(UI *ui);
void initOverheatScreen(UI *ui);

void ui_screen_change(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);

#endif