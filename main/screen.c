#include <string.h>
#include <math.h>
#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"
#include "lvgl.h"
#include "esp_lvgl_port.h"
#include "global_state.h"
#include "screen.h"

// static const char * TAG = "screen";

extern const lv_img_dsc_t bg_logo;
extern const lv_img_dsc_t bg_mining_stat;
extern const lv_img_dsc_t bg_setup;
extern const lv_img_dsc_t bg_network;
extern const lv_img_dsc_t bg_device_info;
extern const lv_img_dsc_t bg_overheat;

static lv_obj_t * screens[MAX_SCREENS];

static screen_t current_screen = -1;
static TickType_t current_screen_counter;

static GlobalState * GLOBAL_STATE;

static lv_obj_t *ui_lbLogoVersion;

static lv_obj_t *ui_lbSetupSSID;
static lv_obj_t *ui_lbSetupIP;

static lv_obj_t *ui_lbMiningHashrate;
static lv_obj_t *ui_lbMiningTarget;
static lv_obj_t *ui_lbMiningBD;
static lv_obj_t *ui_lbMiningAR;
static lv_obj_t *ui_lbBlockFound;

static lv_obj_t * chips_status;
static lv_obj_t *ui_lbDIChip1;
static lv_obj_t *ui_lbDIChip2;
static lv_obj_t *ui_lbDIChip3;
static lv_obj_t *ui_lbDIChip4;
static lv_obj_t *ui_lbDIChip5;
static lv_obj_t *ui_lbDIChip6;
static lv_obj_t *ui_lbDIChip7;
static lv_obj_t *ui_lbDIChip8;
static lv_obj_t *ui_lbDIVin;
static lv_obj_t *ui_lbDIVout;
static lv_obj_t *ui_lbDIIout;
static lv_obj_t *ui_lbDIPwr;
static lv_obj_t *ui_lbDIFanPerc;
static lv_obj_t *ui_lbDITemp;

static lv_obj_t *ui_lbNWSSID;
static lv_obj_t *ui_lbNWIP;
static lv_obj_t *ui_lbNWMAC;
static lv_obj_t *ui_lbNWPool;
static lv_obj_t *ui_lbNWAddr;

static lv_obj_t *ui_lbOHIP;

static lv_obj_t *self_test_message_label;
static lv_obj_t *self_test_result_label;
static lv_obj_t *self_test_finished_label;

static double current_hashrate;
static float current_power;
static uint64_t current_difficulty;
static float curreny_chip_temp;
static bool found_block;

#define SCREEN_UPDATE_MS 500
#define LOGO_DELAY_COUNT 5000 / SCREEN_UPDATE_MS
#define CAROUSEL_DELAY_COUNT 10000 / SCREEN_UPDATE_MS
#define TEXT_RED 0x761330
#define TEXT_GREEN 0x058a37

/* Fonts */
extern const lv_font_t font_XinYin_reg8;
extern const lv_font_t font_XinYin_reg13;
extern const lv_font_t font_XinYin_reg14;
extern const lv_font_t font_XinYin_reg18;

static char* hashSuffixes[] = {' H/s', ' KH/s', ' MH/s', ' GH/s', ' TH/s', ' PH/s', ' EH/s'};
static char* countSuffixes[] = {'', ' K', ' M', ' G', ' T', ' P', ' E'};

static char* hashToStr(double hashrate){
    char ret[32];

    if (hashrate == null || hashrate < 0) {
      return '0';
    }
    double power = floor(log10(hashrate*1000000000)/3);
    if(power<0){
        power = 0;
    }

    char * suffix = hashSuffixes[power];
    float scaled_value = hashrate/pow(1000,power);
    if(scaled_value<10){
        snprintf(ret,32,"%.2f %s",scaled_value,suffix);
    }else if(scaled_value<100){
        snprintf(ret,32,"%.1f %s",scaled_value,suffix);
    }else{
        snprintf(ret,32,"%.0f %s",scaled_value,suffix);
    }
    return ret;
}

static char* countToStr(uint64_t value){
    char ret[32];

    if (value == null || value < 0) {
      return '0';
    }
    double power = floor(log10((double)value)/3);
    if(power<0){
        power = 0;
    }
    
    char * suffix = countSuffixes[power];
    float scaled_value = value/pow(1000,power);
    if(scaled_value<10){
        snprintf(ret,32,"%.2f %s",scaled_value,suffix);
    }else if(scaled_value<100){
        snprintf(ret,32,"%.1f %s",scaled_value,suffix);
    }else{
        snprintf(ret,32,"%.0f %s",scaled_value,suffix);
    }
    return ret;
}

static lv_obj_t *createDefalutLabelWithoutXY(lv_obj_t *parent, uint32_t color, lv_text_align_t align, const lv_font_t *font){
    lv_obj_t *label = lv_label_create(parent);
    lv_obj_set_width(label,LV_SIZE_CONTENT);
    lv_obj_set_height(label,LV_SIZE_CONTENT);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label,lv_color_hex(color),LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(label,align, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(lable,font,LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

static lv_obj_t *createDefalutLabel(lv_obj_t *parent, uint32_t color, lv_text_align_t align, const lv_font_t *font, int32_t x, int32_t y){
    lv_obj_t *label = createDefalutLabelWithoutXY(parent,color,align,font);
    lv_obj_set_x(lable,x);
    lv_obj_set_y(lable,y);

    return label;
}

static lv_obj_t * createDefalutImage(lv_obj_t *parent, const void* src){
    lv_obj_t *img = lv_img_create(parent);
    lv_img_set_src(img, src);
    lv_obj_set_width(img,LV_SIZE_CONTENT);
    lv_obj_set_height(img,LV_SIZE_CONTENT);
    lv_obj_set_align(img, LV_ALIGN_CENTER);
    lv_obj_add_flag(img, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE);

    return img;
}

static lv_obj_t * create_scr_self_test() {
    lv_obj_t * scr = lv_obj_create(NULL);

    lv_obj_set_flex_flow(scr, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(scr, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);

    lv_obj_t *label1 = lv_label_create(scr);
    lv_label_set_text(label1, "BITAXE SELF TEST");

    self_test_message_label = lv_label_create(scr);

    self_test_result_label = lv_label_create(scr);

    self_test_finished_label = lv_label_create(scr);
    lv_obj_set_width(self_test_finished_label, LV_HOR_RES);
    lv_obj_add_flag(self_test_finished_label, LV_OBJ_FLAG_HIDDEN);
    lv_label_set_long_mode(self_test_finished_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(self_test_finished_label, "Self test finished. Press BOOT button for 2 seconds to reset self test status and reboot the device.");

    return scr;
}

static lv_obj_t * create_scr_overheat(SystemModule * module) {
    lv_obj_t * scr = lv_obj_create(NULL);

    lv_obj_clear_flag(scr,LV_OBJ_FLAG_SCROLLABLE);
    
    createDefalutImage(scr, &bg_overheat);

    ui_lbOHIP = createDefalutLabel(src,0x000000,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,100,92);
    lv_label_set_text_fmt(ui_lbOHIP,"IP: %s",module->ip_addr_str);   

    return scr;
}

static lv_obj_t * create_scr_setup(SystemModule * module) {
    lv_obj_t * scr = lv_obj_create(NULL);

    lv_obj_clear_flag(scr,LV_OBJ_FLAG_SCROLLABLE);

    createDefalutImage(scr, &bg_setup);

    ui_lbSetupSSID = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg14,142,67);
    lv_label_set_text_fmt(ui_lbSetupSSID,"%s",module->ap_ssid);

    ui_lbSetupIP = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg14,142,108);
    lv_label_set_text_fmt(ui_lbSetupIP,"%s",module->ap_gw);
    
    return scr;
}

static lv_obj_t * create_scr_logo() {
    lv_obj_t * scr = lv_obj_create(NULL);
    createDefalutImage(scr,&bg_logo);
    return scr;
}

static lv_obj_t * create_scr_mining_stat(SystemModule * module) {
    lv_obj_t * scr = lv_obj_create(NULL);
    createDefalutImage(scr, &bg_mining_stat);
    
    ui_lbMiningHashrate = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_CENTER,&font_XinYin_reg24,6,106);
    lv_obj_set_width(ui_lbMiningHashrate,184);
    lv_obj_set_height(ui_lbMiningHashrate,64);
    lv_label_set_text(ui_lbMiningHashrate,hashToStr(modult->current_hashrate));

    ui_lbMiningTarget = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,265,58);
    lv_label_set_text(ui_lbMiningTarget,countToStr(modult->network_diff));

    ui_lbMiningBD = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,265,85);
    lv_label_set_text(ui_lbMiningBD,modult->best_session_diff_string);

    ui_lbMiningAR = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,265,110);
    lv_label_set_text_fmt(ui_lbMiningAR,"%s/%s",countToStr(module->shares_accepted),countToStr(module->shares_rejected));

    ui_lbBlockFound = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,265,135);
    lv_label_set_text_fmt(ui_lbBlockFound,"%d", module->block_found);

    return scr;
}


static lv_obj_t * create_scr_device_info() {
    lv_obj_t * scr = lv_obj_create(NULL);
    createDefalutImage(scr,&bg_device_info);

    chips_status = lv_obj_create(scr);
    lv_obj_set_flex_flow(chips_status,LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(chips_status, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_width(chips_status,140);
    lv_obj_set_x(chips_status,67);
    lv_obj_set_y(chips_status,48);

    ui_lbDIChip1 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip1,"Dw")
    ui_lbDIChip2 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip2,"Dw")
    ui_lbDIChip3 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip3,"Dw")
    ui_lbDIChip4 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip4,"Dw")
    ui_lbDIChip5 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip5,"Dw")
    ui_lbDIChip6 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip6,"Dw")
    ui_lbDIChip7 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip7,"Dw")
    ui_lbDIChip8 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg8);
    lv_label_set_text(ui_lbDIChip8,"Dw")

    ui_lbDIVin = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,72,90);
    lv_label_set_text(ui_lbDIVin,"V");
    ui_lbDIVout = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,72,132);
    lv_label_set_text(ui_lbDIVout,"V");
    ui_lbDIIout = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,173,90);
    lv_label_set_text(ui_lbDIIout,"A");
    ui_lbDIPwr = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,173,132);
    lv_label_set_text(ui_lbDIPwr,"W");
    ui_lbDIFanPerc = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg18,258,51);
    lv_label_set_text(ui_lbDIFanPerc,"59%");
    ui_lbDITemp = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg18,258,102);
    lv_label_set_text(ui_lbDITemp,"60C");

    return scr;
}

static lv_obj_t * create_scr_network_info() {
    lv_obj_t * scr = lv_obj_create(NULL);
    createDefalutImage(scr,&bg_network);

    ui_lbNWIP = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,74,52);
    lv_label_set_text(ui_lbNWIP,"xxx.xxx.xxx.xxx");
    ui_lbNWSSID = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,74,80);
    lv_label_set_text(ui_lbNWSSID,"bitaxe");
    ui_lbNWPool = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,74,107);
    lv_label_set_text(ui_lbNWPool,"cksolo.xaiten.com:14400");
    ui_lbNWMAC = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg8,214,52);
    lv_label_set_text(ui_lbNWMAC,"AA:BB:CC:DD:EE");

    return scr;
}

static void screen_show(screen_t screen)
{
    if (current_screen != screen) {
        lv_obj_t * scr = screens[screen];

        if (scr && lvgl_port_lock(0)) {
            lv_screen_load_anim(scr, LV_SCR_LOAD_ANIM_FADE_ON, LV_DEF_REFR_PERIOD * 128 / 8, 0, false);
            lvgl_port_unlock();
        }

        current_screen = screen;
        current_screen_counter = 0;
    }
}

static void screen_update_cb(lv_timer_t * timer)
{
    if (GLOBAL_STATE->SELF_TEST_MODULE.active) {

        screen_show(SCR_SELF_TEST);

        SelfTestModule * self_test = &GLOBAL_STATE->SELF_TEST_MODULE;

        lv_label_set_text(self_test_message_label, self_test->message);

        if (self_test->finished) {
            lv_label_set_text(self_test_result_label, self_test->result ? "TESTS PASS!" : "TESTS FAIL!");

            lv_obj_remove_flag(self_test_finished_label, LV_OBJ_FLAG_HIDDEN);
        }

        return;
    }

    SystemModule * module = &GLOBAL_STATE->SYSTEM_MODULE;

    if (module->overheat_mode == 1) {
        if (strcmp(module->ip_addr_str, lv_label_get_text(ip_addr_scr_overheat_label)) != 0) {
            lv_label_set_text(ip_addr_scr_overheat_label, module->ip_addr_str);
        }
        screen_show(SCR_OVERHEAT);
        return;
    }

    if (module->ssid[0] == '\0') {
        screen_show(SCR_CONFIGURE);
        return;
    }

    if (module->ap_enabled) {
        if (strcmp(module->wifi_status, lv_label_get_text(wifi_status_label)) != 0) {
            lv_label_set_text(wifi_status_label, module->wifi_status);
        }
        screen_show(SCR_CONNECTION);
        return;
    }

    current_screen_counter++;

    // Logo

    if (current_screen < SCR_LOGO) {
        screen_show(SCR_LOGO);
        return;
    }

    if (current_screen == SCR_LOGO) {
        if (LOGO_DELAY_COUNT > current_screen_counter) {
            return;
        }
        screen_show(SCR_CAROUSEL_START);
        return;
    }

    // Carousel

    PowerManagementModule * power_management = &GLOBAL_STATE->POWER_MANAGEMENT_MODULE;

    char *pool_url = module->is_using_fallback ? module->fallback_pool_url : module->pool_url;
    if (strcmp(lv_label_get_text(mining_url_scr_urls_label), pool_url) != 0) {
        lv_label_set_text(mining_url_scr_urls_label, pool_url);
    }

    if (strcmp(lv_label_get_text(ip_addr_scr_urls_label), module->ip_addr_str) != 0) {
        lv_label_set_text(ip_addr_scr_urls_label, module->ip_addr_str);
    }

    if (current_hashrate != module->current_hashrate) {
        lv_label_set_text_fmt(hashrate_label, "Gh/s: %.2f", module->current_hashrate);
    }

    if (current_power != power_management->power || current_hashrate != module->current_hashrate) {
        if (power_management->power > 0 && module->current_hashrate > 0) {
            float efficiency = power_management->power / (module->current_hashrate / 1000.0);
            lv_label_set_text_fmt(efficiency_label, "J/Th: %.2f", efficiency);
        }
    }

    if (module->FOUND_BLOCK && !found_block) {
        found_block = true;

        lv_obj_set_width(difficulty_label, LV_HOR_RES);
        lv_label_set_long_mode(difficulty_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_label_set_text_fmt(difficulty_label, "Best: %s   !!! BLOCK FOUND !!!", module->best_session_diff_string);

        screen_show(SCR_STATS);
    } else {
        if (current_difficulty != module->best_session_nonce_diff) {
            lv_label_set_text_fmt(difficulty_label, "Best: %s/%s", module->best_session_diff_string, module->best_diff_string);
        }
    }

    if (curreny_chip_temp != power_management->chip_temp_avg) {
        lv_label_set_text_fmt(chip_temp_label, "Temp: %.1f C", power_management->chip_temp_avg);
    }

    current_hashrate = module->current_hashrate;
    current_power = power_management->power;
    current_difficulty = module->best_session_nonce_diff;
    curreny_chip_temp = power_management->chip_temp_avg;

    if (CAROUSEL_DELAY_COUNT > current_screen_counter || found_block) {
        return;
    }

    screen_next();
}

void screen_next()
{
    if (current_screen >= SCR_CAROUSEL_START) {
        screen_show(current_screen == SCR_CAROUSEL_END ? SCR_CAROUSEL_START : current_screen + 1);
    }
}

esp_err_t screen_start(void * pvParameters)
{
    GLOBAL_STATE = (GlobalState *) pvParameters;

    if (GLOBAL_STATE->SYSTEM_MODULE.is_screen_active) {
        SystemModule * module = &GLOBAL_STATE->SYSTEM_MODULE;

        screens[SCR_SELF_TEST] = create_scr_self_test();
        screens[SCR_OVERHEAT] = create_scr_overheat(module);
        screens[SCR_INVALID_ASIC] = create_scr_invalid_asic(module);
        screens[SCR_CONFIGURE] = create_scr_configure(module);
        screens[SCR_CONNECTION] = create_scr_connection(module);
        screens[SCR_LOGO] = create_scr_logo();
        screens[SCR_URLS] = create_scr_urls(module);
        screens[SCR_STATS] = create_scr_stats();

        lv_timer_create(screen_update_cb, SCREEN_UPDATE_MS, NULL);
    }

    return ESP_OK;
}
