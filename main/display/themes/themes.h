#pragma once

#include "lvgl.h"

class Theme{
    protected:
        const lv_img_dec_t *ui_logoBg;
        const lv_img_dec_t *ui_setupBg;
        const lv_img_dec_t *ui_miningStatBg;
        const lv_img_dec_t *ui_deviceInfoBg;
        const lv_img_dec_t *ui_networkBg;
        const lv_img_dec_t *ui_overheatBg;

    public:
        Theme(){

        }

        //Getters
        const lv_img_dsc_t *getLogoBg() const{
            return ui_logoBg;
        }
        const lv_img_dsc_t *getSetupBg() const{
            return ui_setupBg;
        }
        const lv_img_dsc_t *getMiningStatBg() const{
            return ui_miningStatBg;
        }
        const lv_img_dsc_t *getDeviceInfoBg() const{
            return ui_deviceInfoBg;
        }
        const lv_img_dsc_t *getNetworkBg() const{
            return ui_networkBg;
        }
        const lv_img_dsc_t *getOverheatBg() const{
            return ui_overheatBg;
        }

        //Setter
        void setLogoBg(const lv_img_dsc_t *img){
            ui_logoBg = img;
        }
        void setSetupBg(const lv_img_dsc_t *img){
            ui_setupBg = img;
        }
        void setMiningStatBat(const lv_img_dsc_t *img){
            ui_miningStatBg = img;
        }
        void setDeviceInfoBg(const lv_img_dsc_t *img){
            ui_deviceInfoBg = img;
        }
        void setNetworkBg(const lv_img_dsc_t *img){
            ui_networkBg = img;
        }
        void setOverheatBg(const lv_img_dsc_t *img){
            ui_overheatBg = img;
        }
};

// image files for theme Zyber8S
LV_IMG_DECLARE(logoScreenB);

class ThemeZyber8S : public Theme{
    public:
        ThemeZyber8S() : Theme(){
            setLogoBg(&logoScreenB);
        }
}

class ThemeZyber8G : public Theme{
    public:
        ThemeZyber8S() : Theme(){
            
        }
}