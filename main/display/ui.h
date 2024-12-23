#pragma once

#include "lvgl.h"

#define DISPLAY_LVGL_TICK_PERIOD_MS 30

class DisplayDriver;

class UI{
protected:
    lv_obj_t *ui_logoScreen = nullptr;

public:
    UI();
    

    friend class DisplayDriver;
}