#include "global_state.h"
#include "ui.h"
#include "displayDriver.h"
#include "esp_log.h"
#include "esp_timer.h"

UI::UI(){
    lastScreenChangeTime = 0;
}

lv_obj_t * UI::createDefalutLabel(lv_obj_t *parent, const char *text){
    lv_obj_t *label = lv_label_create(parent);
    lv_obj_set_width(ui_lbLogoVersion,LV_SIZE_CONTENT);
    lv_obj_set_height(ui_lbLogoVersion,LV_SIZE_CONTENT);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_color(ui_lbBestDifficultySet, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_lbBestDifficultySet, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

void UI::initLogoScreen(GlobalState * GLOBAL_STATE){
    Theme *theme = GLOBAL_STATE.theme;

    ui_logoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_logoScreen,LV_OBJ_FLAG_SCROLLABLE);

    ui_logoBgImg = lv_img_create(ui_logoScreen);
    lv_img_set_src(ui_logoBgImg, theme->getLogoBg());
    lv_obj_set_width(ui_logoBgImg,LV_SIZE_CONTENT);
    lv_obj_set_height(ui_logoBgImg,LV_SIZE_CONTENT);
    lv_obj_set_align(ui_logoBgImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_logoBgImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_logoBgImg, LV_OBJ_FLAG_SCROLLABLE);

    ui_lbLogoVersion = createDefalutLabel(ui_logoScreen,"v1.3.3-TCH");



    theme = NULL;
}

void UI::initSetupScreen(GlobalState * GLOBAL_STATE){
    Theme *theme = GLOBAL_STATE.theme;

    ui_setupScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_setupScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui_lbSetupSSID = createDefalutLabel(ui_setupScreen,"Cristalize2.4");

    ui_lbSetupIP = createDefalutLabel(ui_setupScreen,"188.160.86.223");
}

void UI::initMiningStatScreen(GlobalState * GLOBAL_STATE){
    Theme *theme = GLOBAL_STATE.theme;

    ui_miningStatScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_miningStatScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui_lbMiningHashrate = createDefalutLabel(ui_miningStatScreen,"125 TH/s");

    ui_lbMiningTarget = createDefalutLabel(ui_miningStatScreen, "105T");

    ui_lbMiningBD = createDefalutLabel(ui_miningStatScreen, "56G");

    ui_lbMiningAR = createDefalutLabel(ui_miningStatScreen, "122/5");

    ui_lbBlockFound = createDefalutLabel(ui_miningStatScreen, "5");
    

}

void UI::initDeviceInfoScreen(GlobalState * GLOBAL_STATE){
    Theme *theme = GLOBAL_STATE.theme;

    ui_deviceInfoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_deviceInfoScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui_lbDIChips = createDefalutLabel(ui_deviceInfoScreen,"[22, 55, 65, 41, 11, 15, 15, 66]");

    ui_lbDIVin = createDefalutLabel(ui_deviceInfoScreen, "12.1V");

    ui_lbDIVout = createDefalutLabel(ui_deviceInfoScreen, "4.6V");

    ui_lbDIPwr = createDefalutLabel(ui_deviceInfoScreen, "136W");

    ui_lbDIFanPerc = createDefalutLabel(ui_deviceInfoScreen, "55%");

    ui_lbDITemp = createDefalutLabel(ui_deviceInfoScreen, "65");
}

void UI::initNetworkScreen(GlobalState * GLOBAL_STATE){
    Theme *theme = GLOBAL_STATE.theme;

    ui_networkScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_networkScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui_lbNWSSID = createDefalutLabel(ui_networkScreen,"Cristalize2.4");

    ui_lbNWIP = createDefalutLabel(ui_networkScreen, "188.160.86.215");

    ui_lbNWMAC = createDefalutLabel(ui_networkScreen, "44:ab:sd:ds:ww");

    ui_lbNWPool = createDefalutLabel(ui_networkScreen, "xnas.xaietn.com:14500");

    ui_lbNWAddr = createDefalutLabel(ui_networkScreen, "1ER7ciDN5iL9Nr4r9XWiCJYSGA9ERJffkD");
}

void UI::initOverheatScreen(GlobalState * GLOBAL_STATE){
    Theme *theme = GLOBAL_STATE.theme;

    ui_overheatScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_overheatScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui_lbOHIP = createDefalutLabel(ui_overheatScreen,"Cristalize2.4");

}