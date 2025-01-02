#include "ui.h"
#include "esp_log.h"
#include "esp_timer.h"


lv_obj_t *createDefalutLabel(lv_obj_t *parent, const char *text){
    lv_obj_t *label = lv_label_create(parent);
    lv_obj_set_width(label,LV_SIZE_CONTENT);
    lv_obj_set_height(label,LV_SIZE_CONTENT);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_color(label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

void initLogoScreen(UI ui){
    ui.ui_logoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui.ui_logoScreen,LV_OBJ_FLAG_SCROLLABLE);

    ui.ui_logoBgImg = lv_img_create(ui.ui_logoScreen);
    lv_img_set_src(ui.ui_logoBgImg, ui.theme.ui_logoBg);
    lv_obj_set_width(ui.ui_logoBgImg,LV_SIZE_CONTENT);
    lv_obj_set_height(ui.ui_logoBgImg,LV_SIZE_CONTENT);
    lv_obj_set_align(ui.ui_logoBgImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui.ui_logoBgImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui.ui_logoBgImg, LV_OBJ_FLAG_SCROLLABLE);

    ui.ui_lbLogoVersion = createDefalutLabel(ui.ui_logoScreen,"v1.3.3-TCH");

}

void initSetupScreen(UI ui){
    

    ui.ui_setupScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui.ui_setupScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui.ui_lbSetupSSID = createDefalutLabel(ui.ui_setupScreen,"Cristalize2.4");

    ui.ui_lbSetupIP = createDefalutLabel(ui.ui_setupScreen,"188.160.86.223");
}

void initMiningStatScreen(UI ui){
    

    ui.ui_miningStatScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui.ui_miningStatScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui.ui_lbMiningHashrate = createDefalutLabel(ui.ui_miningStatScreen,"125 TH/s");

    ui.ui_lbMiningTarget = createDefalutLabel(ui.ui_miningStatScreen, "105T");

    ui.ui_lbMiningBD = createDefalutLabel(ui.ui_miningStatScreen, "56G");

    ui.ui_lbMiningAR = createDefalutLabel(ui.ui_miningStatScreen, "122/5");

    ui.ui_lbBlockFound = createDefalutLabel(ui.ui_miningStatScreen, "5");
    

}

void initDeviceInfoScreen(UI ui){
    

    ui.ui_deviceInfoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui.ui_deviceInfoScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui.ui_lbDIChips = createDefalutLabel(ui.ui_deviceInfoScreen,"[22, 55, 65, 41, 11, 15, 15, 66]");

    ui.ui_lbDIVin = createDefalutLabel(ui.ui_deviceInfoScreen, "12.1V");

    ui.ui_lbDIVout = createDefalutLabel(ui.ui_deviceInfoScreen, "4.6V");

    ui.ui_lbDIPwr = createDefalutLabel(ui.ui_deviceInfoScreen, "136W");

    ui.ui_lbDIFanPerc = createDefalutLabel(ui.ui_deviceInfoScreen, "55%");

    ui.ui_lbDITemp = createDefalutLabel(ui.ui_deviceInfoScreen, "65");
}

void initNetworkScreen(UI ui){
    

    ui.ui_networkScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui.ui_networkScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui.ui_lbNWSSID = createDefalutLabel(ui.ui_networkScreen,"Cristalize2.4");

    ui.ui_lbNWIP = createDefalutLabel(ui.ui_networkScreen, "188.160.86.215");

    ui.ui_lbNWMAC = createDefalutLabel(ui.ui_networkScreen, "44:ab:sd:ds:ww");

    ui.ui_lbNWPool = createDefalutLabel(ui.ui_networkScreen, "xnas.xaietn.com:14500");

    ui.ui_lbNWAddr = createDefalutLabel(ui.ui_networkScreen, "1ER7ciDN5iL9Nr4r9XWiCJYSGA9ERJffkD");
}

void initOverheatScreen(UI ui){
    

    ui.ui_overheatScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui.ui_overheatScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image

    //Labels
    ui.ui_lbOHIP = createDefalutLabel(ui.ui_overheatScreen,"Cristalize2.4");

}