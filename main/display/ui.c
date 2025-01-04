#include "ui.h"
#include "esp_log.h"
#include "esp_timer.h"

static const char * TAG = "UI";

lv_obj_t *createDefalutLabel(lv_obj_t *parent, const char *text){
    lv_obj_t *label = lv_label_create(parent);
    lv_obj_set_width(label,LV_SIZE_CONTENT);
    lv_obj_set_height(label,LV_SIZE_CONTENT);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

lv_obj_t * createDefalutImage(lv_obj_t *parent, const void* src){
    lv_obj_t *img = lv_img_create(parent);
    lv_img_set_src(img, src);
    lv_obj_set_width(img,LV_SIZE_CONTENT);
    lv_obj_set_height(img,LV_SIZE_CONTENT);
    lv_obj_set_align(img, LV_ALIGN_CENTER);
    lv_obj_add_flag(img, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE);

    return img;
}

void initLogoScreen(UI *ui){
    ui->ui_logoScreen = lv_obj_create(NULL);
    
    lv_obj_clear_flag(ui->ui_logoScreen,LV_OBJ_FLAG_SCROLLABLE);

    //ui->ui_logoBgImg = createDefalutImage(ui->ui_logoScreen,ui->theme.ui_logoBg);
    ui->ui_logoBgImg = lv_img_create(ui->ui_logoScreen);
    lv_img_set_src(ui->ui_logoBgImg, ui->theme.ui_logoBg);
    lv_obj_set_width(ui->ui_logoBgImg,LV_SIZE_CONTENT);
    lv_obj_set_height(ui->ui_logoBgImg,LV_SIZE_CONTENT);
    lv_obj_set_align(ui->ui_logoBgImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui->ui_logoBgImg, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui->ui_logoBgImg, LV_OBJ_FLAG_SCROLLABLE);

    ui->ui_lbLogoVersion = createDefalutLabel(ui->ui_logoScreen,"v1.3.3-TCH");
    lv_obj_set_style_text_color(ui->ui_lbLogoVersion, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_x(ui->ui_lbLogoVersion,101);
    lv_obj_set_y(ui->ui_lbLogoVersion,93);
    lv_obj_set_style_text_align(ui->ui_lbLogoVersion, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_lbLogoVersion, &font_XinYin_reg14, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void initSetupScreen(UI *ui){
    ui->ui_setupScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->ui_setupScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image
    ui->ui_setupBgImg = createDefalutImage(ui->ui_setupScreen,ui->theme.ui_setupBg);

    //Labels
    ui->ui_lbSetupSSID = createDefalutLabel(ui->ui_setupScreen,"Cristalize2.4");

    ui->ui_lbSetupIP = createDefalutLabel(ui->ui_setupScreen,"188.160.86.223");
}

void initMiningStatScreen(UI *ui){
    

    ui->ui_miningStatScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->ui_miningStatScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image
    ui->ui_miningStatBgImg = createDefalutImage(ui->ui_miningStatScreen,ui->theme.ui_setupBg);
    //Labels
    ui->ui_lbMiningHashrate = createDefalutLabel(ui->ui_miningStatScreen,"125 TH/s");

    ui->ui_lbMiningTarget = createDefalutLabel(ui->ui_miningStatScreen, "105T");

    ui->ui_lbMiningBD = createDefalutLabel(ui->ui_miningStatScreen, "56G");

    ui->ui_lbMiningAR = createDefalutLabel(ui->ui_miningStatScreen, "122/5");

    ui->ui_lbBlockFound = createDefalutLabel(ui->ui_miningStatScreen, "5");
    

}

void initDeviceInfoScreen(UI *ui){
    

    ui->ui_deviceInfoScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->ui_deviceInfoScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image
    ui->ui_deviceInfoBgImg = createDefalutImage(ui->ui_deviceInfoScreen,ui->theme.ui_deviceInfoBg);

    //Labels
    ui->ui_lbDIChips = createDefalutLabel(ui->ui_deviceInfoScreen,"[22, 55, 65, 41, 11, 15, 15, 66]");

    ui->ui_lbDIVin = createDefalutLabel(ui->ui_deviceInfoScreen, "12.1V");

    ui->ui_lbDIVout = createDefalutLabel(ui->ui_deviceInfoScreen, "4.6V");

    ui->ui_lbDIPwr = createDefalutLabel(ui->ui_deviceInfoScreen, "136W");

    ui->ui_lbDIFanPerc = createDefalutLabel(ui->ui_deviceInfoScreen, "55%%");

    ui->ui_lbDITemp = createDefalutLabel(ui->ui_deviceInfoScreen, "65");
}

void initNetworkScreen(UI *ui){
    

    ui->ui_networkScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->ui_networkScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image
    ui->ui_networkBgImg = createDefalutImage(ui->ui_networkScreen,ui->theme.ui_networkBg);

    //Labels
    ui->ui_lbNWSSID = createDefalutLabel(ui->ui_networkScreen,"Cristalize2.4");

    ui->ui_lbNWIP = createDefalutLabel(ui->ui_networkScreen, "188.160.86.215");

    ui->ui_lbNWMAC = createDefalutLabel(ui->ui_networkScreen, "44:ab:sd:ds:ww");

    ui->ui_lbNWPool = createDefalutLabel(ui->ui_networkScreen, "xnas.xaietn.com:14500");

    ui->ui_lbNWAddr = createDefalutLabel(ui->ui_networkScreen, "1ER7ciDN5iL9Nr4r9XWiCJYSGA9ERJffkD");
}

void initOverheatScreen(UI *ui){
    

    ui->ui_overheatScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui->ui_overheatScreen,LV_OBJ_FLAG_SCROLLABLE);

    //Background Image
    ui->ui_overheatBgImg = createDefalutImage(ui->ui_overheatScreen,ui->theme.ui_overheatBg);

    //Labels
    ui->ui_lbOHIP = createDefalutLabel(ui->ui_overheatScreen,"Cristalize2.4");

}

void ui_screen_change(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay){
    lv_scr_load_anim(target, fademode, spd, delay, false);
}