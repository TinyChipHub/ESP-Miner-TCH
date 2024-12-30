#pragma once

#include "lvgl.h"

#define DISPLAY_LVGL_TICK_PERIOD_MS 30

class DisplayDriver;

class UI{
private:
    lv_obj_t * createDefalutLabel(lv_obj_t *parent, const char* text);

protected:
    //login screen
    lv_obj_t *ui_logoScreen = nullptr;
    lv_obj_t *ui_logoBgImg = nullptr;
    lv_obj_t *ui_lbLogoVersion = nullptr;
    
    lv_obj_t *ui_setupScreen = nullptr;
    lv_obj_t *ui_setupBgImg = nullptr;
    lv_obj_t *ui_lbSetupSSID = nullptr;
    lv_obj_t *ui_lbSetupIP = nullptr;

    lv_obj_t *ui_miningStatScreen = nullptr;
    lv_obj_t *ui_miningStatBgImg = nullptr;
    lv_obj_t *ui_lbMiningHashrate = nullptr;
    lv_obj_t *ui_lbMiningTarget = nullptr;
    lv_obj_t *ui_lbMiningBD = nullptr;
    lv_obj_t *ui_lbMiningAR = nullptr;
    lv_obj_t *ui_lbBlockFound = nullptr;

    lv_obj_t *ui_deviceInfoScreen = nullptr;
    lv_obj_t *ui_deviceInfoBgImg = nullptr;
    lv_obj_t *ui_lbDIChips = nullptr;
    lv_obj_t *ui_lbDIVin = nullptr;
    lv_obj_t *ui_lbDIVout = nullptr;
    lv_obj_t *ui_lbDIPwr = nullptr;
    lv_obj_t *ui_lbDIFanPerc = nullptr;
    lv_obj_t *ui_lbDITemp = nullptr;

    lv_obj_t *ui_networkScreen = nullptr;
    lv_obj_t *ui_networkBgImg = nullptr;
    lv_obj_t *ui_lbNWSSID = nullptr;
    lv_obj_t *ui_lbNWIP = nullptr;
    lv_obj_t *ui_lbNWMAC = nullptr;
    lv_obj_t *ui_lbNWPool = nullptr;
    lv_obj_t *ui_lbNWAddr = nullptr;
    
    lv_obj_t *ui_overheatScreen = nullptr;
    lv_obj_t *ui_overheatBgImg = nullptr;
    lv_obj_t *ui_lbOHIP = nullptr;

    int64_t lastScreenChangeTime;

    void initLogoScreen(GlobalState * GLOBAL_STATE);
    void initSetupScreen(GlobalState * GLOBAL_STATE);
    void initMiningStatScreen(GlobalState * GLOBAL_STATE);
    void initDeviceInfoScreen(GlobalState * GLOBAL_STATE);
    void initNetworkScreen(GlobalState * GLOBAL_STATE);
    void initOverheatScreen(GlobalState * GLOBAL_STATE);

public:
    UI();
    


    friend class DisplayDriver;
}