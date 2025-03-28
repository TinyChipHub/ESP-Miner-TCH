#include <string.h>
#include <math.h>
#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"
#include "lvgl.h"
#include "esp_lvgl_port.h"
#include "global_state.h"
#include "vcore.h"
#include "screen.h"
#include "nvs_config.h"
#include "display.h"

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
static lv_obj_t * chips_label[8];
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
#define TEXT_YELLOW 0xf5cf39

#define MAX_SCREEN_IDEL_TIME 300000 //5 mins

/* Fonts */
extern const lv_font_t font_XinYin_reg10;
extern const lv_font_t font_XinYin_reg12;
extern const lv_font_t font_XinYin_reg13;
extern const lv_font_t font_XinYin_reg14;
extern const lv_font_t font_XinYin_reg18;
extern const lv_font_t font_XinYin_reg22;

static char* hashSuffixes[] = {" H/s", " KH/s", " MH/s", " GH/s", " TH/s", " PH/s", " EH/s"};
static char* countSuffixes[] = {"", " K", " M", " G", " T", " P", " E"};

static const char * TAG = "SCREEN-DEBUG";
static bool display_off = false;

static char* hashToStr(char *ret, size_t len, double hashrate){

    if (hashrate <= 0) {
        snprintf(ret,len,"0 H/s");
        return ret;
    }
    int power = floor(log10(hashrate*1000000000)/3);
    if(power<0){
        power = 0;
    }

    char * suffix = hashSuffixes[power];
    float scaled_value = hashrate*1000000000/pow(1000,power);
    if(scaled_value<10){
        snprintf(ret,len,"%.2f%s",scaled_value,suffix);
    }else if(scaled_value<100){
        snprintf(ret,len,"%.1f%s",scaled_value,suffix);
    }else{
        snprintf(ret,len,"%.0f%s",scaled_value,suffix);
    }
    return ret;
}

static char* countToStr(char *ret, size_t len, uint64_t value, bool roundup){

    if (value <= 0) {
      snprintf(ret,len,"0");
      return ret;
    }
    int power = floor(log10((double)value)/3);
    if(power<0){
        power = 0;
    }
    
    char * suffix = countSuffixes[power];
    float scaled_value = value/pow(1000,power);
    if(roundup){
        snprintf(ret,len,"%.0f%s",scaled_value,suffix);
    }else{
        if(scaled_value<10){
            snprintf(ret,len,"%.2f%s",scaled_value,suffix);
        }else if(scaled_value<100){
            snprintf(ret,len,"%.1f%s",scaled_value,suffix);
        }else{
            snprintf(ret,len,"%.0f%s",scaled_value,suffix);
        }
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
    lv_obj_set_style_text_font(label,font,LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

static lv_obj_t *createDefalutLabel(lv_obj_t *parent, uint32_t color, lv_text_align_t align, const lv_font_t *font, int32_t x, int32_t y){
    lv_obj_t *label = createDefalutLabelWithoutXY(parent,color,align,font);
    lv_obj_set_x(label,x);
    lv_obj_set_y(label,y);

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

    ui_lbOHIP = createDefalutLabel(scr,0x000000,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,100,92);
    lv_label_set_text_fmt(ui_lbOHIP,"IP: %s",module->ip_addr_str);   

    return scr;
}

static lv_obj_t * create_scr_setup(SystemModule * module) {
    lv_obj_t * scr = lv_obj_create(NULL);

    lv_obj_clear_flag(scr,LV_OBJ_FLAG_SCROLLABLE);

    createDefalutImage(scr, &bg_setup);

    ui_lbSetupSSID = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg14,142,69);
    lv_label_set_text_fmt(ui_lbSetupSSID,"%s",module->ap_ssid);

    ui_lbSetupIP = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg14,142,112);
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
    
    ui_lbMiningHashrate = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_CENTER,&font_XinYin_reg22,6,106);
    lv_obj_set_size(ui_lbMiningHashrate,184,64);
    int fontHeight = lv_font_get_line_height(&font_XinYin_reg22);
    int verPad = (64 - fontHeight)/2;
    lv_obj_set_style_pad_top(ui_lbMiningHashrate, verPad, 0);

    //ui_lbMiningHashrate = lv_label_create(scr);

    
    
    lv_label_set_text(ui_lbMiningHashrate,"0 H/s"); 

    ui_lbMiningTarget = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,265,58);
    lv_label_set_text(ui_lbMiningTarget,"102T");//countToStr(module->network_diff));

    ui_lbMiningBD = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,265,85);
    lv_label_set_text(ui_lbMiningBD,module->best_session_diff_string);

    ui_lbMiningAR = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,265,110);
    lv_label_set_text_fmt(ui_lbMiningAR,"%s/%s","0","0");

    ui_lbBlockFound = createDefalutLabel(scr,0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,265,135);
    lv_label_set_text_fmt(ui_lbBlockFound,"%d", (int)module->block_found);

    return scr;
}


static lv_obj_t * create_scr_device_info() {
    lv_obj_t * scr = lv_obj_create(NULL);
    createDefalutImage(scr,&bg_device_info);

    chips_status = lv_obj_create(scr);
    lv_obj_set_flex_flow(chips_status,LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(chips_status, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_width(chips_status,155);
    lv_obj_set_height(chips_status,LV_SIZE_CONTENT);
    lv_obj_clear_flag(chips_status, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(chips_status,0,0);
    lv_obj_set_style_pad_top(chips_status,0,0);
    lv_obj_set_style_border_width(chips_status,0,0);
    lv_obj_set_x(chips_status,60);
    lv_obj_set_y(chips_status,48);

    ui_lbDIChip1 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    chips_label[0] = ui_lbDIChip1;
    lv_label_set_text(ui_lbDIChip1,"Dw");
    
    ui_lbDIChip2 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    chips_label[1] = ui_lbDIChip2;
    lv_label_set_text(ui_lbDIChip2,"Dw");
    
    ui_lbDIChip3 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    chips_label[2] = ui_lbDIChip3;
    lv_label_set_text(ui_lbDIChip3,"Dw");
    
    ui_lbDIChip4 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    chips_label[3] = ui_lbDIChip4;
    lv_label_set_text(ui_lbDIChip4,"Dw");
    
    ui_lbDIChip5 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    chips_label[4] = ui_lbDIChip5;
    lv_label_set_text(ui_lbDIChip5,"Dw");
    
    ui_lbDIChip6 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    lv_label_set_text(ui_lbDIChip6,"Dw");
    chips_label[5] = ui_lbDIChip6;

    ui_lbDIChip7 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    lv_label_set_text(ui_lbDIChip7,"Dw");
    chips_label[6] = ui_lbDIChip7;

    ui_lbDIChip8 = createDefalutLabelWithoutXY(chips_status, TEXT_RED, LV_TEXT_ALIGN_AUTO, &font_XinYin_reg10);
    lv_label_set_text(ui_lbDIChip8,"Dw");
    chips_label[7] = ui_lbDIChip8;

    ui_lbDIVin = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,72,90);
    lv_label_set_text(ui_lbDIVin,"V");
    ui_lbDIVout = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,72,132);
    lv_label_set_text(ui_lbDIVout,"V");
    ui_lbDIIout = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,173,90);
    lv_label_set_text(ui_lbDIIout,"A");
    ui_lbDIPwr = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg13,173,132);
    lv_label_set_text(ui_lbDIPwr,"W");
    ui_lbDIFanPerc = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg18,246,52);
    lv_label_set_text(ui_lbDIFanPerc,"59%");
    ui_lbDITemp = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg18,246,102);
    lv_label_set_text(ui_lbDITemp,"60C");

    return scr;
}

static lv_obj_t * create_scr_network_info(SystemModule * module) {
    lv_obj_t * scr = lv_obj_create(NULL);
    createDefalutImage(scr,&bg_network);

    ui_lbNWIP = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,72,52);
    lv_label_set_text(ui_lbNWIP,"xxx.xxx.xxx.xxx");
    ui_lbNWSSID = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,72,80);
    lv_label_set_text(ui_lbNWSSID,"bitaxe");
    ui_lbNWPool = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg12,72,107);
    lv_label_set_text(ui_lbNWPool,"cksolo.xaiten.com:14400");
    ui_lbNWMAC = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg10,212,52);
    lv_label_set_long_mode(ui_lbNWMAC, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_width(ui_lbNWMAC,80);
    lv_label_set_text(ui_lbNWMAC,module->mac);
    ui_lbNWAddr = createDefalutLabel(scr, 0xffffff,LV_TEXT_ALIGN_LEFT,&font_XinYin_reg10,72,135);
    lv_label_set_text(ui_lbNWAddr,"afB223jjs");
    lv_label_set_long_mode(ui_lbNWAddr, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_width(ui_lbNWAddr,205);

    return scr;
}

static void screen_show(screen_t screen)
{
    if (current_screen != screen) {
        lv_obj_t * scr = screens[screen];

        if (scr && lvgl_port_lock(0)) {
            lv_screen_load_anim(scr, LV_SCR_LOAD_ANIM_FADE_ON, 350, 0, false);
            lvgl_port_unlock();
        }

        current_screen = screen;
        current_screen_counter = 0;
    }
}

static uint32_t temp_chips_count[8];
static uint32_t temp_chips_fail_count[8];

static void screen_update_cb(lv_timer_t * timer)
{
    if (display_off){
        return ;
    }else{
        if(lv_disp_get_inactive_time(NULL)>MAX_SCREEN_IDEL_TIME){
            if(lvgl_port_lock(0)){
                ESP_LOGI(TAG,"Maxx screen idel excess, turn off the screen now");
                //lvgl_port_stop();
                gpio_set_level(DISPLAY_PIN_PWR, false);
                gpio_set_level(DISPLAY_PIN_BK_PWR, DISPLAY_LCD_BK_LIGHT_OFF);
                display_off=true;
                lvgl_port_unlock();
            }
        }
    }

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
        if (strcmp(module->ip_addr_str, lv_label_get_text(ui_lbOHIP)) != 0) {
            lv_label_set_text(ui_lbOHIP, module->ip_addr_str);
        }
        screen_show(SCR_OVERHEAT);
        return;
    }

    if (module->ap_enabled) {
        if (strcmp(module->ap_ssid, lv_label_get_text(ui_lbSetupSSID)) != 0) {
            lv_label_set_text(ui_lbSetupSSID, module->ap_ssid);
        }
        if (strcmp(module->ap_gw, lv_label_get_text(ui_lbSetupIP)) != 0) {
            lv_label_set_text(ui_lbSetupIP, module->ap_gw);
        }
        screen_show(SCR_SETUP);
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

    // Carousel update

    PowerManagementModule * power_management = &GLOBAL_STATE->POWER_MANAGEMENT_MODULE;

    /*Mining stat. update*/
    //ESP_LOGW(TAG,"Hashrate: %.02f",module->current_hashrate);
    char hr[16];
    //snprintf(hr,16,"%.02f GH/s",module->current_hashrate);
    lv_label_set_text(ui_lbMiningHashrate,hashToStr(hr,16,module->current_hashrate));
    
    // char *temp = countToStr(module->network_diff);
    char nwTra[8];
    countToStr(nwTra,8,module->network_diff,false);
    if(strcmp(lv_label_get_text(ui_lbMiningTarget), nwTra) != 0){
        lv_label_set_text(ui_lbMiningTarget,nwTra);
    }

    if(strcmp(lv_label_get_text(ui_lbMiningBD), module->best_session_diff_string) != 0){
        lv_label_set_text(ui_lbMiningBD,module->best_session_diff_string);
    }

    char an[6];
    char rn[6];
    lv_label_set_text_fmt(ui_lbMiningAR,"%s/%s",countToStr(an,6,module->shares_accepted,true),countToStr(rn,6,module->shares_rejected,true));
    lv_label_set_text_fmt(ui_lbBlockFound,"%d",(int)module->block_found);

    /*Devie info. update*/
    if (CAROUSEL_DELAY_COUNT <= current_screen_counter){
        for(int a=0;a<8;a++){
            if(temp_chips_count[a]<GLOBAL_STATE->chip_submit[a]){
                if(temp_chips_count[a]==0){
                    lv_label_set_text(chips_label[a],"Up");
                    lv_obj_set_style_text_color(chips_label[a],lv_color_hex(TEXT_GREEN),LV_PART_MAIN|LV_STATE_DEFAULT);
                }
                temp_chips_fail_count[a]=0;
                temp_chips_count[a]=GLOBAL_STATE->chip_submit[a];
            }else{
                if(temp_chips_count[a]>0){
                    temp_chips_fail_count[a]++;
                    if(temp_chips_fail_count[a]>=10){
                        lv_label_set_text(chips_label[a],"Dw");
                        lv_obj_set_style_text_color(chips_label[a],lv_color_hex(TEXT_RED),LV_PART_MAIN|LV_STATE_DEFAULT);
                    }else if(temp_chips_fail_count[a]>=3){
                        lv_label_set_text(chips_label[a],"Wa");
                        lv_obj_set_style_text_color(chips_label[a],lv_color_hex(TEXT_YELLOW),LV_PART_MAIN|LV_STATE_DEFAULT);
                    }
                }
            }
        }
    }
    lv_label_set_text_fmt(ui_lbDIVin,"%.1fV",power_management->voltage/1000);
    lv_label_set_text_fmt(ui_lbDIVout,"%.02fV",power_management->outVoltage_mv/GLOBAL_STATE->voltage_domain);///1000/GLOBAL_STATE->voltage_domain);
    lv_label_set_text_fmt(ui_lbDIPwr,"%.1fW",power_management->power);
    lv_label_set_text_fmt(ui_lbDIIout,"%.1fA",power_management->current/1000);
    lv_label_set_text_fmt(ui_lbDITemp,"%.1fC",power_management->chip_temp_avg);
    lv_label_set_text_fmt(ui_lbDIFanPerc,"%.1f%%",(double)power_management->fan_perc);

    /*Network*/
    char *pool_url = module->is_using_fallback ? module->fallback_pool_url : module->pool_url;
    if (strcmp(lv_label_get_text(ui_lbNWPool), pool_url) != 0) {
        lv_label_set_text(ui_lbNWPool, pool_url);
    }

    if (strcmp(lv_label_get_text(ui_lbNWSSID), module->ssid) != 0) {
        lv_label_set_text(ui_lbNWSSID, module->ssid);
    }

    if (strcmp(lv_label_get_text(ui_lbNWIP), module->ip_addr_str) != 0) {
        lv_label_set_text(ui_lbNWIP, module->ip_addr_str);
    }

    //char *user = nvs_config_get_string(module->is_using_fallback?NVS_CONFIG_FALLBACK_STRATUM_USER:NVS_CONFIG_STRATUM_USER,"");
    if (strcmp(lv_label_get_text(ui_lbNWAddr), module->mining_addr) != 0) {
        lv_label_set_text(ui_lbNWAddr, module->mining_addr);
    }

    if (strcmp(lv_label_get_text(ui_lbNWMAC), module->mac) != 0) {
        lv_label_set_text(ui_lbNWMAC,module->mac);
    }
    

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

void display_short_press(void){
    //lvgl_port_resume();
    if(lvgl_port_lock(0)){
        ESP_LOGW(TAG,"display switch on");
        gpio_set_level(DISPLAY_PIN_PWR, true);
        gpio_set_level(DISPLAY_PIN_BK_PWR, DISPLAY_LCD_BK_LIGHT_ON);
        //lvgl_port_resume();
        display_off=false;
        screen_next();
        lvgl_port_unlock();
    }
}

void display_long_press(void){
    if(lvgl_port_lock(0)){
        ESP_LOGW(TAG,"display_long_press_cb");
        //lvgl_port_stop();
        gpio_set_level(DISPLAY_PIN_PWR, false);
        gpio_set_level(DISPLAY_PIN_BK_PWR, DISPLAY_LCD_BK_LIGHT_OFF);
        display_off=true;
        lvgl_port_unlock();
    }
}

esp_err_t screen_start(void * pvParameters)
{
    GLOBAL_STATE = (GlobalState *) pvParameters;

    if (GLOBAL_STATE->SYSTEM_MODULE.is_screen_active) {
        SystemModule * module = &GLOBAL_STATE->SYSTEM_MODULE;

        screens[SCR_SELF_TEST] = create_scr_self_test();
        screens[SCR_OVERHEAT] = create_scr_overheat(module);
        screens[SCR_SETUP] = create_scr_setup(module);
        screens[SCR_LOGO] = create_scr_logo();
        screens[SCR_MINING_STAT] = create_scr_mining_stat(module);
        screens[SCR_DEVICE_INFO] = create_scr_device_info();
        screens[SCR_NETWORK] = create_scr_network_info(module);

        lv_timer_create(screen_update_cb, SCREEN_UPDATE_MS, NULL);
    }

    return ESP_OK;
}
