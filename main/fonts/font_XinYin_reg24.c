/*******************************************************************************
 * Size: 24 px
 * Bpp: 3
 * Opts: --bpp 3 --size 24 --font ZiTiQuanXinYiLOGOTi-2.ttf --symbols abcdefghijklmnopqrstuvwxyz,.:0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ|{}"?!@#$%^&*()-_√×/\;'` --range 32-127 --format lvgl -o font_XinYin_reg24.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#ifndef FONT_XINYIN_REG24
#define FONT_XINYIN_REG24 1
#endif

#if FONT_XINYIN_REG24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x5f, 0xd0, 0xf, 0xff, 0x5a, 0xfe, 0x8b, 0x69,
    0x82, 0x6e, 0x7, 0xf8,

    /* U+0022 "\"" */
    0x5f, 0xa8, 0x9f, 0x98, 0x1f, 0xfe, 0xa5, 0xfa,
    0x89, 0xf9, 0x80,

    /* U+0023 "#" */
    0x3, 0x14, 0xa0, 0x9, 0x60, 0x3d, 0x6e, 0x22,
    0xdb, 0x81, 0xe2, 0x4, 0x40, 0xc4, 0xf, 0x30,
    0x31, 0x2, 0xe0, 0x47, 0xf1, 0x2, 0xf8, 0xa,
    0x76, 0x18, 0x1f, 0xfc, 0x12, 0x1, 0x20, 0x11,
    0x44, 0x9, 0x23, 0xa, 0xf0, 0x29, 0x58, 0x15,
    0xa2, 0x4, 0x40, 0x98, 0x60, 0x8, 0x1e, 0xe0,
    0x44, 0x10, 0xc, 0xd, 0xf9, 0x81, 0x7e, 0x2,
    0x5f, 0x2, 0x7, 0xff, 0x5, 0x80, 0x68, 0x8,
    0xb2, 0x4, 0x9f, 0x6, 0x40, 0x12, 0x88, 0xa,
    0xc4, 0x4, 0xc0, 0xb8, 0x20, 0x7f, 0x92, 0xc0,
    0xa4, 0x60, 0x60,

    /* U+0027 "'" */
    0x5f, 0xa8, 0x1f, 0xfc, 0xc5, 0xfa, 0x80,

    /* U+0028 "(" */
    0x0, 0xf7, 0xf9, 0x9, 0x4, 0xf, 0x30, 0x33,
    0x72, 0x3, 0x79, 0x4, 0xc, 0xc0, 0xff, 0xff,
    0x81, 0xc4, 0xc, 0xc0, 0x92, 0x1, 0x10, 0x35,
    0xfc, 0x86, 0x3, 0xf1, 0xf1, 0x2c, 0xc0,

    /* U+0029 ")" */
    0x5f, 0xec, 0xc0, 0xf8, 0xc6, 0x1b, 0x80, 0xd0,
    0x19, 0x1c, 0xc, 0x80, 0xcc, 0xf, 0xff, 0xf8,
    0x1c, 0x40, 0xf9, 0x20, 0x13, 0x5f, 0xa8, 0x11,
    0x20, 0x3e, 0xe1, 0xa5, 0xa7, 0x20,

    /* U+002A "*" */
    0x1, 0x3d, 0x0, 0xa0, 0x13, 0x62, 0xd8, 0x29,
    0x9d, 0x2, 0x75, 0xd0, 0x27, 0xa, 0x61, 0x3e,
    0xa8, 0x14, 0x60, 0x27, 0xa0, 0x0,

    /* U+002B "+" */
    0x3, 0x92, 0x88, 0x1f, 0x8d, 0xb4, 0x3, 0xff,
    0xbe, 0x6d, 0xa0, 0x12, 0xb6, 0x6c, 0x96, 0x3,
    0x25, 0x50, 0x3f, 0xf8, 0x2b, 0xfb, 0x1, 0x2f,
    0xec, 0x7, 0xff, 0xa0,

    /* U+002C "," */
    0x5f, 0xa0, 0x1f, 0x96, 0x14, 0x68, 0x40,

    /* U+002D "-" */
    0x16, 0xff, 0xd0, 0xa5, 0xff, 0x30, 0x3f, 0xf8,
    0x20,

    /* U+002E "." */
    0x3, 0x2f, 0xd4, 0xf, 0xc0,

    /* U+002F "/" */
    0x3, 0xe9, 0xfc, 0x80, 0xf9, 0x80, 0x28, 0xf,
    0x30, 0x2a, 0x7, 0xd4, 0x9, 0x81, 0xe4, 0x40,
    0x30, 0x3e, 0x80, 0x50, 0xf, 0x12, 0x0, 0x80,
    0xfa, 0x1, 0x40, 0x3e, 0x40, 0x9, 0x1, 0xe8,
    0x5, 0x0, 0xf9, 0x81, 0x20, 0x3c, 0xc0, 0xa0,
    0x1f, 0x50, 0x26, 0x7, 0x91, 0x0, 0xc0, 0xfb,
    0x81, 0x50, 0x3c, 0x50, 0x4, 0x40, 0xf5, 0x2,
    0xe0, 0x7c,

    /* U+0030 "0" */
    0x0, 0xf7, 0xff, 0xe8, 0x4, 0xe1, 0x3, 0xfc,
    0xe8, 0x8, 0x6, 0x4d, 0xe2, 0x4, 0x90, 0x81,
    0xbd, 0x93, 0x64, 0x5, 0x98, 0x13, 0x3, 0xee,
    0x7, 0xff, 0xfc, 0xf, 0xff, 0xab, 0x2, 0x60,
    0x7d, 0xc0, 0xc4, 0xd, 0xec, 0x9b, 0x20, 0x2c,
    0x20, 0x19, 0x37, 0x88, 0x11, 0x41, 0xc2, 0x7,
    0xf9, 0xe0,

    /* U+0031 "1" */
    0xff, 0x1, 0xff, 0xf4,

    /* U+0032 "2" */
    0x7, 0xff, 0xfa, 0x90, 0x3f, 0xf8, 0x6b, 0x20,
    0x24, 0xbf, 0x88, 0x15, 0x0, 0x6d, 0xfe, 0xc8,
    0x9, 0x81, 0xff, 0xc0, 0xe0, 0x5c, 0xf, 0xfe,
    0x81, 0xa0, 0x58, 0x9, 0xef, 0xfd, 0x80, 0x8a,
    0x1, 0x61, 0x3, 0xf8, 0xe0, 0x11, 0x1, 0x25,
    0xcd, 0xae, 0x2, 0x60, 0x56, 0xfa, 0x42, 0x2,
    0x20, 0x45, 0x1, 0xff, 0xd0, 0x20, 0x45, 0x1,
    0xff, 0xc0, 0x60, 0x56, 0xff, 0xa0, 0x8, 0x80,
    0x92, 0xfe, 0x60, 0x56, 0x10, 0x3f, 0xf8, 0x0,

    /* U+0033 "3" */
    0x7f, 0xff, 0xf0, 0x20, 0x1f, 0xfc, 0x47, 0x80,
    0x14, 0xbf, 0xc0, 0x46, 0x85, 0x6f, 0xfb, 0x81,
    0x22, 0x7, 0xff, 0x1, 0x81, 0x30, 0x3f, 0xf8,
    0x84, 0xf, 0xfe, 0x3, 0x2, 0x40, 0xdb, 0xfd,
    0xc0, 0x89, 0x4, 0xbf, 0xc0, 0x68, 0x7, 0xff,
    0x12, 0x80, 0x7f, 0xff, 0x62, 0x5, 0x0, 0xff,
    0x8f, 0x2, 0x40, 0x7f, 0xf0, 0x8, 0x1f, 0xfc,
    0x46, 0x4, 0xd5, 0xbf, 0xed, 0x0, 0xa1, 0x4b,
    0xfc, 0x40, 0xa1, 0x3, 0xff, 0x82, 0x6b, 0x0,

    /* U+0034 "4" */
    0x3, 0xe9, 0xff, 0x90, 0x1f, 0x8b, 0x3, 0xff,
    0x87, 0x0, 0x90, 0x1f, 0xf2, 0x40, 0xc, 0x81,
    0xff, 0x40, 0x28, 0x7, 0xfc, 0x88, 0x8, 0x7,
    0xff, 0x2, 0x81, 0x30, 0x3f, 0xe6, 0x5, 0x0,
    0xff, 0xe0, 0x40, 0x5, 0x81, 0xff, 0x40, 0x28,
    0x7, 0xfc, 0x58, 0x4, 0x80, 0x7f, 0xa6, 0x2,
    0x5f, 0xe6, 0x5, 0x7d, 0x3, 0xff, 0x8b, 0x92,
    0xfe, 0x20, 0x49, 0x32, 0xb7, 0xf9, 0x1, 0x7a,
    0xc0, 0xff, 0xeb, 0x0,

    /* U+0035 "5" */
    0x3f, 0xff, 0xf0, 0xa8, 0x1f, 0xfc, 0xb4, 0xbf,
    0xd8, 0xe, 0x56, 0xff, 0x98, 0x1f, 0xfd, 0xb6,
    0x7, 0xff, 0x0, 0x81, 0x1f, 0xff, 0x52, 0x4,
    0x80, 0xff, 0x96, 0x40, 0x2c, 0x69, 0x7c, 0x40,
    0xa8, 0x13, 0x96, 0xfd, 0x90, 0x13, 0x3, 0xff,
    0x81, 0xc0, 0xb8, 0x1f, 0xfd, 0x1e, 0x5, 0xc5,
    0xbf, 0xec, 0x80, 0x99, 0x4b, 0xfc, 0x40, 0xa8,
    0x1f, 0xfc, 0x25, 0x90,

    /* U+0036 "6" */
    0x2, 0x33, 0xff, 0xf3, 0x2, 0x59, 0x81, 0xff,
    0xc1, 0x34, 0xc, 0x97, 0xe2, 0x3, 0x81, 0x2f,
    0x6f, 0xe4, 0x0, 0x81, 0x50, 0x3f, 0xe2, 0x4,
    0x80, 0xff, 0xe0, 0x30, 0x22, 0x7, 0xff, 0x11,
    0xff, 0xfa, 0x1, 0xff, 0xc4, 0x7c, 0x81, 0xc5,
    0x2f, 0x1, 0xb8, 0x1c, 0xad, 0xf7, 0x20, 0xa,
    0x60, 0x7f, 0xd4, 0x8, 0x90, 0x12, 0x3, 0xff,
    0x82, 0x40, 0x18, 0x7, 0xa8, 0x11, 0x1c, 0x9,
    0xeb, 0x77, 0x20, 0xa, 0x6, 0x81, 0x14, 0xb0,
    0x1b, 0x81, 0x2c, 0x80, 0xfc, 0xf9, 0x0,

    /* U+0037 "7" */
    0xbf, 0xff, 0xf0, 0xe0, 0x1f, 0xfc, 0x5c, 0x97,
    0xfc, 0x40, 0xce, 0xdf, 0xf8, 0xd, 0x0, 0xff,
    0x99, 0x1, 0x0, 0xff, 0xe0, 0x40, 0x5, 0x81,
    0xff, 0x40, 0x28, 0x7, 0xfc, 0x58, 0x4, 0x80,
    0x7f, 0xd0, 0xa, 0x1, 0xff, 0x24, 0x0, 0xc8,
    0x1f, 0xf4, 0x2, 0x80, 0x7f, 0xcc, 0x80, 0xa0,
    0x7f, 0xf0, 0x20, 0x2, 0x80, 0xff, 0xa8, 0x17,
    0x3, 0xfe, 0x28, 0x3, 0x20, 0x7f, 0xdc, 0xa,
    0x1, 0xff, 0x32, 0x2, 0x1, 0xf8,

    /* U+0038 "8" */
    0x2, 0x57, 0xff, 0xd0, 0x81, 0x9d, 0x40, 0x7e,
    0x78, 0x80, 0x30, 0x8, 0xa5, 0x80, 0xdc, 0x5,
    0x2, 0x7a, 0xdd, 0xc8, 0x2, 0x82, 0x2, 0x80,
    0x7a, 0x1, 0x60, 0x3f, 0xf8, 0x4, 0xe, 0x40,
    0x50, 0xf, 0x50, 0x2c, 0x28, 0x13, 0xd6, 0xee,
    0x40, 0x90, 0x28, 0x8, 0xa5, 0x80, 0xd0, 0x3,
    0x40, 0x7f, 0xf0, 0x21, 0x10, 0xa, 0x7f, 0xe4,
    0x5, 0x8, 0x12, 0x60, 0x7a, 0x81, 0x20, 0x3f,
    0xf8, 0xa4, 0x9, 0x10, 0x3c, 0x80, 0x88, 0x40,
    0x5a, 0xdf, 0x80, 0xa0, 0xa4, 0x9, 0x2f, 0x1,
    0x24, 0x1, 0x99, 0x3, 0xf1, 0x94, 0x0,

    /* U+0039 "9" */
    0x2, 0x5b, 0xff, 0xaa, 0x3, 0xad, 0x10, 0x3e,
    0x56, 0x1, 0x34, 0x4, 0x52, 0x88, 0x13, 0x60,
    0x10, 0xa, 0xeb, 0x6d, 0x40, 0xa0, 0x20, 0x49,
    0x0, 0xe4, 0xc0, 0x98, 0x1f, 0xfc, 0xc, 0x5,
    0xc8, 0x13, 0x3, 0xff, 0x82, 0x40, 0x1a, 0x40,
    0xff, 0xb8, 0x12, 0xdf, 0xf5, 0x3, 0x8d, 0x3,
    0xff, 0x88, 0xbc, 0x69, 0x7c, 0x7, 0xe7, 0x2d,
    0xf7, 0x3, 0xff, 0x89, 0x80, 0xb8, 0x1f, 0xf2,
    0x60, 0x4c, 0x5, 0xbf, 0xb5, 0x2, 0x60, 0xa,
    0x5f, 0x88, 0x13, 0x80, 0x7f, 0xf0, 0x55, 0x80,
    0x0,

    /* U+003A ":" */
    0x3, 0x2f, 0xd4, 0xf, 0xcb, 0xf5, 0x3, 0x2f,
    0xd4, 0xf, 0xc0,

    /* U+0041 "A" */
    0x3, 0xef, 0xf5, 0x3, 0xff, 0x82, 0xc0, 0xc8,
    0xf, 0xfe, 0xd, 0x3, 0x98, 0x1f, 0xf2, 0x20,
    0x75, 0x3, 0xfe, 0xe0, 0x48, 0x1, 0x40, 0x7f,
    0x90, 0x5, 0x0, 0xb8, 0x1f, 0xd0, 0xb, 0x94,
    0x1, 0x1, 0xfc, 0xc0, 0x90, 0xe0, 0x50, 0xf,
    0x90, 0x13, 0x0, 0x80, 0x98, 0x1f, 0x70, 0x28,
    0x5, 0x0, 0x90, 0x1c, 0x50, 0x4, 0x6, 0x60,
    0x50, 0xe, 0xa0, 0x5c, 0xe, 0x40, 0x9, 0x1,
    0x98, 0x2, 0x80, 0xee, 0x5, 0x40, 0x98, 0x15,
    0x3, 0xc8, 0x80, 0x60, 0x54, 0xb, 0x5b, 0x40,
    0x2a, 0x4, 0xc1, 0x20, 0x24, 0xb3, 0x40, 0x18,
    0x15, 0x14, 0xf, 0xe8, 0x4, 0xc0, 0x12,

    /* U+0042 "B" */
    0x1f, 0xff, 0xf0, 0x29, 0x3, 0xff, 0x88, 0xb3,
    0x3, 0xe6, 0xfc, 0x40, 0xa1, 0x3, 0x8c, 0x9e,
    0xcc, 0xa, 0x81, 0xff, 0xc1, 0xa0, 0x48, 0xf,
    0xfe, 0x9d, 0x2, 0x40, 0x71, 0xb7, 0xd9, 0x81,
    0x50, 0x3c, 0x97, 0x88, 0x12, 0x20, 0x7f, 0xf1,
    0x13, 0x3, 0x8f, 0xff, 0x40, 0x28, 0x7, 0xff,
    0x5, 0x90, 0x22, 0x7, 0xff, 0x5, 0x81, 0xff,
    0xc4, 0x28, 0x8, 0x81, 0x8d, 0xbf, 0x60, 0x26,
    0x7, 0x92, 0xf8, 0x8, 0xc0, 0x3f, 0xf8, 0x46,
    0x60, 0x0,

    /* U+0043 "C" */
    0x2, 0x5b, 0xff, 0xfb, 0x0, 0x94, 0x81, 0xff,
    0xc1, 0x4c, 0x8, 0xb7, 0xfc, 0x84, 0x2, 0x9a,
    0x4f, 0xf0, 0x20, 0x4c, 0xf, 0xff, 0xf8, 0x1f,
    0xff, 0xd2, 0x4, 0xc0, 0xff, 0xe0, 0x40, 0x29,
    0xad, 0xfe, 0x81, 0x30, 0x22, 0x97, 0xf8, 0x4,
    0xa4, 0xf, 0xfe, 0x0,

    /* U+0044 "D" */
    0x1f, 0xff, 0xd9, 0x81, 0xff, 0xc3, 0x33, 0x1,
    0xf3, 0x7c, 0x80, 0x8d, 0x3, 0x8c, 0x9d, 0x70,
    0x12, 0x40, 0x3f, 0xe3, 0x40, 0xb8, 0x1f, 0xfc,
    0x4, 0x4, 0xc0, 0xff, 0xff, 0x81, 0xff, 0xdb,
    0x60, 0x4c, 0xf, 0xf8, 0xc0, 0x2e, 0x6, 0x36,
    0xf6, 0xc0, 0x24, 0x80, 0x72, 0x5c, 0x40, 0x8d,
    0x3, 0xff, 0x82, 0x66, 0x0,

    /* U+0045 "E" */
    0x3, 0x4d, 0xff, 0xfb, 0x0, 0x3d, 0x90, 0x3f,
    0xf8, 0x38, 0xc, 0x9b, 0xfc, 0x84, 0x2, 0x3e,
    0xc9, 0xfc, 0x10, 0x17, 0x3, 0xff, 0x80, 0x40,
    0x88, 0x1f, 0xfc, 0x32, 0x7, 0xff, 0x10, 0xc9,
    0xff, 0xc0, 0x3, 0x9b, 0xff, 0x90, 0x1f, 0xfc,
    0x93, 0xff, 0xfd, 0x80, 0xff, 0xe3, 0x10, 0x4,
    0xf, 0xfe, 0xa, 0x2, 0xc0, 0x7f, 0xf0, 0x20,
    0x11, 0xf6, 0xff, 0x40, 0x18, 0xc, 0x97, 0xf8,
    0x1, 0xec, 0x81, 0xff, 0x0,

    /* U+0046 "F" */
    0x3, 0x4d, 0xff, 0xfb, 0x0, 0x3d, 0x90, 0x3f,
    0xf8, 0x38, 0xc, 0x9b, 0xfc, 0x84, 0x2, 0x5e,
    0xc9, 0xfc, 0x10, 0x15, 0x3, 0xff, 0x80, 0x40,
    0x10, 0x3f, 0xfc, 0xc6, 0xdf, 0xfa, 0x1, 0xc9,
    0x7f, 0xf0, 0x0, 0xff, 0xe4, 0x9f, 0xff, 0xec,
    0x7, 0xff, 0xfc, 0xf, 0xf0,

    /* U+0047 "G" */
    0x3, 0x3d, 0xff, 0xfb, 0x1, 0x68, 0x40, 0xff,
    0xe0, 0xe2, 0x4, 0x9b, 0xfc, 0x83, 0x20, 0x5a,
    0xc9, 0xfc, 0x28, 0x15, 0x20, 0x7f, 0xc4, 0x9,
    0x1, 0xff, 0xc3, 0x20, 0x7f, 0xf3, 0x64, 0x98,
    0x1f, 0xfc, 0x16, 0xea, 0x7, 0xff, 0x68, 0x81,
    0xff, 0xc1, 0x20, 0x48, 0xf, 0xfe, 0x4, 0x2,
    0xa4, 0xf, 0xf9, 0x10, 0x2d, 0x96, 0xf0, 0x1e,
    0xc4, 0x8, 0xa5, 0xc0, 0x7d, 0xa1, 0x3, 0xfe,

    /* U+0048 "H" */
    0x1f, 0xd8, 0xf, 0xdf, 0xd8, 0xf, 0xff, 0xf8,
    0x1f, 0xfd, 0x33, 0x27, 0xd4, 0xf, 0xe6, 0xfe,
    0x40, 0x7f, 0xf3, 0x4f, 0xff, 0x80, 0xff, 0xff,
    0x81, 0xff, 0xd3,

    /* U+0049 "I" */
    0xff, 0x1, 0xff, 0xf4,

    /* U+004A "J" */
    0x3, 0xfb, 0x7f, 0x1, 0xff, 0xff, 0x3, 0xff,
    0xfe, 0x7, 0xff, 0x4, 0x90, 0x1f, 0xfc, 0xe,
    0x4, 0xc2, 0xb7, 0xdc, 0x81, 0x40, 0x52, 0xf0,
    0x1b, 0x1, 0xfe, 0x2f, 0x90, 0x0,

    /* U+004B "K" */
    0x1f, 0xd8, 0xf, 0x2f, 0xf3, 0x3, 0xfc, 0x68,
    0x13, 0x60, 0x3f, 0xd8, 0x9, 0x40, 0x3f, 0xd8,
    0x8, 0xd0, 0x3f, 0xd4, 0x80, 0x38, 0xf, 0xf4,
    0x40, 0x5c, 0xf, 0xf3, 0x60, 0x2c, 0x40, 0xfe,
    0x50, 0xa, 0x90, 0x3f, 0xd4, 0x9, 0x20, 0x1f,
    0xf5, 0x2, 0x48, 0x7, 0xfc, 0xa0, 0x15, 0x20,
    0x7f, 0xcd, 0x80, 0xb1, 0x3, 0xfe, 0x88, 0xb,
    0x81, 0xff, 0xc0, 0xa4, 0x1, 0xc0, 0x7f, 0xf0,
    0x30, 0x11, 0xa0, 0x7f, 0xf0, 0x30, 0x12, 0x80,
    0x7f, 0xc6, 0x81, 0x36,

    /* U+004C "L" */
    0x1f, 0xd8, 0xf, 0xff, 0xf8, 0x1f, 0xff, 0xf0,
    0x22, 0x7, 0xf8, 0x81, 0x10, 0x3f, 0x90, 0x17,
    0x3, 0xfa, 0x1, 0x1f, 0x6f, 0x90, 0xc, 0x6,
    0x4b, 0xc4, 0x1, 0xec, 0x81, 0xf8,

    /* U+004D "M" */
    0xff, 0x20, 0x3f, 0xbf, 0xc4, 0xd, 0x40, 0xfd,
    0x0, 0xff, 0x40, 0x3c, 0x98, 0x1f, 0xe6, 0x80,
    0xe8, 0x7, 0xff, 0x2, 0x81, 0xa1, 0x3, 0xff,
    0x83, 0x0, 0x16, 0x7, 0xfc, 0xc0, 0x34, 0x38,
    0x12, 0x3, 0xf4, 0x2, 0x90, 0x40, 0x50, 0x3f,
    0xd4, 0x1, 0x60, 0x12, 0x1, 0xfe, 0x4c, 0xe,
    0xa0, 0x7f, 0xf0, 0x21, 0x2, 0x80, 0x7f, 0xf0,
    0xb7, 0xf3, 0x3, 0xff, 0xfe, 0x7, 0xff, 0x3c,

    /* U+004E "N" */
    0x1f, 0xe2, 0x7, 0xdf, 0xd8, 0xe, 0xe0, 0x7f,
    0xf1, 0xc, 0x3, 0xff, 0x88, 0xd0, 0x1f, 0xfc,
    0x4a, 0x7, 0xff, 0x16, 0x81, 0xff, 0xc0, 0x30,
    0x2, 0x60, 0x7f, 0xf0, 0x1a, 0x1, 0x8, 0x1f,
    0xfc, 0xa, 0x5, 0xc0, 0xff, 0xe0, 0xd0, 0x6,
    0x1, 0xff, 0xc0, 0x4c, 0x3, 0x40, 0x7f, 0xf0,
    0x21, 0x1, 0x40, 0xff, 0xe0, 0xf0, 0x3f, 0xf8,
    0x86, 0x1, 0xff, 0xc4, 0x64, 0xf, 0xfe, 0x27,
    0x3, 0xff, 0x88, 0x68, 0x18,

    /* U+004F "O" */
    0x0, 0x77, 0xff, 0xea, 0x40, 0x1c, 0x40, 0xff,
    0x2c, 0x2, 0x1, 0x93, 0x79, 0x1, 0xa0, 0x40,
    0x5a, 0xc9, 0xac, 0x2, 0x40, 0x62, 0x40, 0x79,
    0x81, 0xff, 0xff, 0x3, 0xff, 0xf2, 0x48, 0xf,
    0x30, 0x39, 0x1, 0x6b, 0x7d, 0x0, 0x90, 0x80,
    0x64, 0xbc, 0x6, 0x80, 0xe4, 0x7, 0xf9, 0x70,

    /* U+0050 "P" */
    0x1f, 0xff, 0xf0, 0x2a, 0x3, 0xff, 0x88, 0xac,
    0x3, 0xe6, 0xfc, 0x40, 0x9a, 0x3, 0x8c, 0x9e,
    0xd0, 0xa, 0x1, 0xff, 0xc1, 0x64, 0x1, 0x20,
    0x3f, 0xf8, 0x2c, 0xf, 0xfe, 0x2b, 0x2, 0x20,
    0x7f, 0xf0, 0x19, 0x0, 0x40, 0xe3, 0x6f, 0xb4,
    0x2, 0x80, 0x79, 0x2f, 0x10, 0x26, 0x80, 0xff,
    0xe1, 0x2b, 0x0, 0xf1, 0xff, 0xf5, 0x40, 0x7f,
    0xff, 0xc0, 0xff, 0xe3, 0x0,

    /* U+0051 "Q" */
    0x0, 0x77, 0xff, 0xea, 0x40, 0x1c, 0x40, 0xff,
    0x2c, 0x2, 0x1, 0x92, 0xf0, 0x1a, 0x4, 0x5,
    0xad, 0xf4, 0x2, 0x40, 0x62, 0x40, 0x79, 0x81,
    0xff, 0xff, 0x3, 0xff, 0xbc, 0x88, 0x1f, 0xfc,
    0x25, 0x70, 0x1f, 0x89, 0x1, 0xb0, 0x1f, 0x20,
    0x2d, 0x6e, 0x20, 0x72, 0x10, 0xc, 0x97, 0x1,
    0xd4, 0x1c, 0x40, 0xff, 0xe0, 0x20, 0x7, 0x7f,
    0xfe, 0x51, 0x81, 0xff, 0xc2, 0xac, 0x0,

    /* U+0052 "R" */
    0x1f, 0xff, 0xf0, 0x2a, 0x3, 0xff, 0x88, 0xac,
    0x3, 0xe6, 0xfc, 0x40, 0x9a, 0x3, 0x8c, 0x9e,
    0xd0, 0xa, 0x1, 0xff, 0xc1, 0x64, 0x1, 0x20,
    0x3f, 0xf8, 0x2c, 0xf, 0xfe, 0x2b, 0x2, 0x20,
    0x7f, 0xf0, 0x19, 0x0, 0x40, 0xe3, 0x6f, 0xb4,
    0x2, 0x80, 0x79, 0x2f, 0x10, 0x26, 0x80, 0xff,
    0xe1, 0xa8, 0x7, 0x8f, 0xfe, 0x20, 0x10, 0x1f,
    0xfc, 0x2a, 0x4, 0xc0, 0xff, 0xe0, 0xb0, 0x2a,
    0x7, 0xff, 0x9, 0x80, 0x24, 0x7, 0xff, 0x6,
    0x81, 0x40, 0x3f, 0xf8, 0x24, 0x80, 0x20,

    /* U+0053 "S" */
    0x2, 0x7b, 0xff, 0xf5, 0x2, 0xd0, 0x81, 0xff,
    0xc1, 0x84, 0x9, 0x37, 0xfb, 0x0, 0x60, 0x5a,
    0xc9, 0xf9, 0x82, 0x4, 0x88, 0x1f, 0xf1, 0x2,
    0x60, 0x7f, 0xf0, 0x48, 0x3, 0x0, 0xff, 0xe0,
    0x40, 0x27, 0xff, 0xd4, 0x81, 0x28, 0x7, 0xf9,
    0x64, 0x4, 0xf3, 0x4b, 0xc0, 0x6a, 0x6, 0x32,
    0xdf, 0x74, 0x4, 0xc0, 0xff, 0xe0, 0x70, 0x2e,
    0x7, 0xff, 0x47, 0x81, 0x70, 0xad, 0xfe, 0xe8,
    0x9, 0x8c, 0x97, 0xf0, 0x1a, 0x81, 0xff, 0xc2,
    0x59, 0x0,

    /* U+0054 "T" */
    0xbf, 0xff, 0xf0, 0xc8, 0x1f, 0xfc, 0x5c, 0x97,
    0x1, 0x92, 0xf1, 0x76, 0xf2, 0x2, 0x96, 0xf0,
    0x1f, 0xff, 0xf0, 0x3f, 0xff, 0xe0, 0x7f, 0xff,
    0x0,

    /* U+0055 "U" */
    0x1f, 0xd8, 0xf, 0xdf, 0xd8, 0xf, 0xff, 0xf8,
    0x1f, 0xff, 0xf0, 0x3f, 0xfb, 0xa4, 0xf, 0xfe,
    0x29, 0x3, 0xcc, 0xe, 0x40, 0x5a, 0xdf, 0x40,
    0x24, 0x20, 0x19, 0x2f, 0x1, 0xa0, 0x38, 0x81,
    0xfe, 0x5c, 0x0,

    /* U+0056 "V" */
    0xbf, 0xc4, 0xf, 0xbf, 0xb0, 0xe0, 0x54, 0xf,
    0x20, 0x24, 0x10, 0x13, 0x3, 0xdc, 0xa, 0x80,
    0x60, 0x48, 0xe, 0x40, 0x9, 0x0, 0xa0, 0x58,
    0xc, 0xc0, 0xa8, 0x11, 0x2, 0x60, 0x6a, 0x4,
    0xc0, 0xcc, 0x9, 0x1, 0x10, 0x8, 0xe, 0xa0,
    0x5c, 0x3, 0x2, 0xc0, 0x71, 0x20, 0x8, 0x5,
    0x2, 0x60, 0x7a, 0x81, 0x32, 0x40, 0x10, 0x1f,
    0x20, 0x2d, 0x40, 0xb8, 0x1f, 0x12, 0x0, 0x98,
    0x12, 0x3, 0xf5, 0x3, 0xcc, 0xf, 0xe6, 0x7,
    0xb0, 0x1f, 0xe4, 0x7, 0x20, 0x3f, 0xdc, 0xc,
    0xc0, 0xff, 0x90, 0x1a, 0x81, 0xe0,

    /* U+0057 "W" */
    0x7f, 0xcc, 0xf, 0xb7, 0xf3, 0x3, 0xed, 0xfc,
    0x18, 0x16, 0x3, 0xc4, 0x80, 0xb0, 0x1e, 0x24,
    0x1, 0x0, 0x20, 0x10, 0x1e, 0xa0, 0x64, 0x7,
    0xa8, 0x17, 0x1, 0x40, 0x98, 0x1c, 0xc0, 0xe6,
    0x7, 0x30, 0x24, 0x1, 0x81, 0x50, 0x31, 0x3,
    0xd4, 0xc, 0x40, 0x90, 0x19, 0x0, 0x24, 0x5,
    0x40, 0xf1, 0x20, 0x2a, 0x5, 0xc0, 0xdc, 0xa,
    0x81, 0x30, 0x2a, 0x5, 0x40, 0x98, 0x12, 0x3,
    0x20, 0x24, 0x1, 0x1, 0x34, 0x4, 0x80, 0x20,
    0x26, 0x7, 0x90, 0x2, 0x43, 0x81, 0x50, 0x80,
    0x12, 0x1c, 0xa, 0x81, 0xee, 0x5, 0x42, 0x0,
    0x48, 0x70, 0x2a, 0x10, 0x2, 0x40, 0x79, 0x1,
    0x36, 0x2, 0xa0, 0x10, 0x13, 0x60, 0x24, 0x7,
    0xe6, 0x5, 0x0, 0x90, 0x13, 0x2, 0x80, 0x54,
    0xf, 0xd4, 0xf, 0x12, 0x2, 0xa0, 0x78, 0x90,
    0x1f, 0x89, 0x1, 0xd4, 0xc, 0x48, 0xe, 0xa0,
    0x7f, 0x90, 0x1c, 0xc0, 0xe4, 0x7, 0x30, 0x3f,
    0xd4, 0xc, 0x80, 0xf5, 0x3, 0x20, 0x3f, 0xe2,
    0x40, 0x58, 0xf, 0x12, 0x2, 0xc0, 0x78,

    /* U+0058 "X" */
    0x7f, 0xd8, 0xf, 0x4f, 0xec, 0x1a, 0x0, 0x60,
    0x18, 0xb0, 0x2e, 0x2, 0x81, 0x32, 0x5, 0xc0,
    0xa1, 0x2, 0x80, 0x5c, 0x4, 0x20, 0x13, 0x3,
    0x34, 0x0, 0xc2, 0xc0, 0xa8, 0x1e, 0xa0, 0x4f,
    0x1, 0x50, 0x3f, 0x50, 0x3c, 0x90, 0xf, 0xc9,
    0x0, 0xea, 0x7, 0xfa, 0x1, 0xa0, 0x1f, 0xf4,
    0x3, 0x40, 0x3f, 0xc9, 0x0, 0xea, 0x7, 0xf5,
    0x3, 0xc9, 0x0, 0xfa, 0x81, 0x3c, 0x5, 0x40,
    0xf3, 0x40, 0xc, 0x2c, 0xa, 0x81, 0xd0, 0xb,
    0x80, 0x84, 0x2, 0x60, 0x54, 0x9, 0x90, 0x2e,
    0x5, 0x8, 0x68, 0x1, 0x80, 0x62, 0xc0, 0xb8,

    /* U+0059 "Y" */
    0x7f, 0xcc, 0xf, 0x1f, 0xea, 0x1a, 0x1, 0x8,
    0x1d, 0xc0, 0xa8, 0xa, 0x5, 0xc0, 0xd0, 0x80,
    0xa0, 0x6a, 0x0, 0xc0, 0x9, 0x80, 0x68, 0xc,
    0x90, 0x3, 0x22, 0x80, 0x30, 0xf, 0x52, 0x3,
    0x50, 0x2e, 0x7, 0xee, 0x4, 0x80, 0x42, 0x7,
    0xe2, 0xc0, 0xc9, 0x81, 0xfe, 0x80, 0x68, 0x7,
    0xff, 0x0, 0x81, 0x10, 0x3f, 0xff, 0xe0, 0x7f,
    0xf9, 0x80,

    /* U+005A "Z" */
    0x9f, 0xff, 0xf0, 0xd0, 0x1f, 0xfc, 0x5c, 0x97,
    0xf8, 0x81, 0x9a, 0xb7, 0xfc, 0x40, 0x99, 0x3,
    0xfd, 0x80, 0x8c, 0x3, 0xfd, 0x8, 0x17, 0x3,
    0xfc, 0x98, 0x15, 0x20, 0x7f, 0x1a, 0x5, 0x10,
    0x1f, 0xee, 0x4, 0x98, 0x1f, 0xea, 0x40, 0x1a,
    0x7, 0xf9, 0xa0, 0x2e, 0x7, 0xf9, 0x40, 0x2a,
    0x40, 0xff, 0x50, 0x26, 0x80, 0xff, 0x60, 0x23,
    0x0, 0xfc, 0xae, 0x20, 0x4e, 0xdf, 0xc7, 0x22,
    0x6, 0x4b, 0xf9, 0x81, 0xff, 0xc5,

    /* U+0061 "a" */
    0x1, 0x3f, 0xf6, 0x97, 0xf9, 0x8, 0xc0, 0xf1,
    0x68, 0xe, 0x60, 0x64, 0xa2, 0x7, 0xfd, 0xad,
    0xb7, 0x60, 0x7e, 0x24, 0x7, 0x70, 0x3f, 0xff,
    0x84, 0x80, 0xee, 0x7, 0xf6, 0xb6, 0xdd, 0x81,
    0xcc, 0xc, 0x94, 0x40, 0xfa, 0x30, 0x3c, 0x5a,
    0x3, 0x0,

    /* U+0062 "b" */
    0x1f, 0xd8, 0xf, 0xff, 0xa4, 0xdf, 0xfa, 0x81,
    0xe2, 0xc8, 0x1e, 0x58, 0xf, 0x8a, 0x50, 0x18,
    0xa0, 0x31, 0xfa, 0xdb, 0x90, 0x3f, 0xf8, 0x68,
    0xf, 0xfe, 0x1f, 0x3, 0xff, 0xc7, 0xc0, 0xff,
    0xe1, 0xa0, 0x3f, 0x1f, 0xad, 0xb1, 0x3, 0xfc,
    0x52, 0x88, 0x11, 0x40, 0x62, 0xc8, 0x1e, 0x58,
    0x0,

    /* U+0063 "c" */
    0x0, 0xb7, 0xff, 0xe0, 0xa, 0x90, 0x3f, 0xf8,
    0x10, 0xc, 0x97, 0xe0, 0x4, 0xb, 0x5b, 0xf8,
    0xe, 0x24, 0x7, 0xff, 0xf4, 0x90, 0x1f, 0xe2,
    0x5, 0xad, 0xfc, 0x2, 0x1, 0x92, 0xfc, 0x1,
    0x52, 0x7, 0xfc,

    /* U+0064 "d" */
    0x3, 0xfe, 0x7f, 0xc8, 0xf, 0xff, 0x34, 0xff,
    0xda, 0x60, 0x3a, 0x30, 0x3c, 0x5a, 0x3, 0x98,
    0x19, 0x28, 0x81, 0xff, 0x6b, 0x6d, 0xd8, 0x1f,
    0x89, 0x1, 0xdc, 0xf, 0xff, 0xe1, 0x20, 0x3b,
    0x81, 0xfd, 0xad, 0xb7, 0x60, 0x73, 0x3, 0x25,
    0x10, 0x3e, 0x8c, 0xf, 0x16, 0x80, 0xc0,

    /* U+0065 "e" */
    0x0, 0x6f, 0xff, 0xa8, 0x11, 0xc8, 0xf, 0xca,
    0x80, 0x80, 0x45, 0x28, 0x81, 0x20, 0x8, 0xb,
    0x5b, 0x60, 0x3f, 0x88, 0x1f, 0xfc, 0x23, 0x6e,
    0xc0, 0x7f, 0x92, 0xc4, 0x9, 0x1, 0xff, 0xc1,
    0x54, 0xe, 0x3f, 0xfd, 0x40, 0xf1, 0x3, 0xfe,
    0x40, 0x5a, 0xdf, 0x98, 0x8, 0x4, 0x52, 0xfb,
    0x0, 0x39, 0x1, 0xff, 0x0,

    /* U+0066 "f" */
    0x2, 0x3b, 0xf9, 0x0, 0x38, 0x81, 0xe8, 0x4,
    0x53, 0x0, 0x80, 0xb5, 0x3f, 0x80, 0xdf, 0x90,
    0x1f, 0xc9, 0x0, 0xc9, 0x1d, 0xa0, 0x23, 0x68,
    0x81, 0xff, 0xff, 0x3, 0xc0,

    /* U+0067 "g" */
    0x1, 0x3f, 0xed, 0x5c, 0xfe, 0x62, 0x30, 0x38,
    0xa8, 0xc0, 0xe6, 0x6, 0x4a, 0x3, 0xff, 0x81,
    0xad, 0xbd, 0x20, 0x7e, 0x24, 0x6, 0x54, 0xf,
    0xfe, 0xe1, 0x3, 0xff, 0x89, 0x0, 0x95, 0x80,
    0x71, 0x2, 0x7f, 0xd5, 0x1, 0xe8, 0x7, 0xff,
    0xd, 0x66, 0x94, 0xe5, 0xf0, 0xf, 0x19, 0x6d,
    0x1a, 0x3, 0xff, 0x8b, 0x80, 0x88, 0x56, 0xfe,
    0xc8, 0x9, 0xc, 0x97, 0xe2, 0x5, 0x0, 0xff,
    0xe0, 0x9a, 0xc0,

    /* U+0068 "h" */
    0x1f, 0xd8, 0xf, 0xff, 0x79, 0x9b, 0xfe, 0x60,
    0x7c, 0xc8, 0x1d, 0x18, 0x1f, 0x14, 0x80, 0x68,
    0x7, 0x1f, 0xad, 0x60, 0x3f, 0xf8, 0x44, 0x80,
    0xff, 0xff, 0x81, 0xff, 0xe5,

    /* U+0069 "i" */
    0xbf, 0xc0, 0x7f, 0xc4, 0xe1, 0x36, 0x85, 0xfe,
    0x3, 0xff, 0xd8,

    /* U+006A "j" */
    0x2, 0xbf, 0xc4, 0xf, 0xfe, 0x39, 0x3c, 0x5,
    0x7f, 0x80, 0xd3, 0x68, 0x81, 0xff, 0xff, 0x3,
    0xff, 0x88, 0x80, 0x8c, 0xb8, 0x8, 0x86, 0x88,
    0x17, 0x3, 0x96, 0x20,

    /* U+006B "k" */
    0x1f, 0xd8, 0xf, 0xff, 0x9a, 0xff, 0x20, 0x3f,
    0xa8, 0x13, 0x40, 0x7e, 0xa0, 0x68, 0x7, 0xe4,
    0x80, 0x54, 0xf, 0xea, 0x4, 0x90, 0xf, 0xd0,
    0xd, 0x40, 0xfe, 0x60, 0x4c, 0xf, 0xf4, 0x2,
    0x64, 0xf, 0xe6, 0xc0, 0x58, 0xf, 0xf4, 0x20,
    0x58, 0xf, 0xf6, 0x2, 0x34, 0xf, 0xf6, 0x2,
    0x4c, 0xf, 0xe3, 0x0, 0xa2,

    /* U+006C "l" */
    0xbf, 0xc4, 0xf, 0xff, 0xf8, 0x1c,

    /* U+006D "m" */
    0x6, 0xff, 0xd9, 0x9b, 0xff, 0xa0, 0x16, 0x40,
    0x71, 0x99, 0x1, 0xe7, 0x44, 0x3, 0x24, 0x3,
    0xc5, 0x10, 0x24, 0xa0, 0x2b, 0x6e, 0x6, 0x5a,
    0xe4, 0x4, 0x48, 0x9, 0x1, 0x20, 0x2e, 0x5,
    0x80, 0xb8, 0x1f, 0x88, 0x1f, 0x10, 0x3f, 0xff,
    0xe0, 0x7f, 0xff, 0xc0,

    /* U+006E "n" */
    0x0, 0xb7, 0xff, 0x52, 0x4, 0xa9, 0x3, 0xe5,
    0x88, 0x8, 0x6, 0x4a, 0x3, 0x40, 0x4, 0xb,
    0x5b, 0x60, 0x24, 0x7, 0x12, 0x2, 0x20, 0x7f,
    0xf0, 0xc8, 0x1f, 0xff, 0xf0, 0x3f, 0xfa, 0xc0,

    /* U+006F "o" */
    0x0, 0xb7, 0xff, 0x52, 0x4, 0xa9, 0x3, 0xe5,
    0x88, 0x8, 0x6, 0x4a, 0x3, 0x40, 0x4, 0xb,
    0x5b, 0x60, 0x24, 0x7, 0x12, 0x2, 0x20, 0x7f,
    0xf0, 0xc8, 0x1f, 0xfe, 0x2, 0x7, 0xe2, 0x40,
    0x44, 0xf, 0x10, 0x2d, 0x6d, 0x80, 0x88, 0x8,
    0x6, 0x4a, 0x3, 0x70, 0xa, 0x90, 0x3e, 0x38,
    0x80,

    /* U+0070 "p" */
    0x1f, 0xd9, 0xdf, 0xfd, 0x40, 0xf1, 0x88, 0xf,
    0x2c, 0x7, 0xc5, 0x36, 0x20, 0x45, 0x1, 0xdb,
    0x2c, 0x8c, 0x40, 0xfc, 0x48, 0xe, 0x40, 0x7f,
    0xf0, 0xf8, 0x1f, 0xfe, 0x3e, 0x7, 0xe2, 0x40,
    0x72, 0x3, 0xfb, 0x7b, 0x6c, 0x40, 0xff, 0x92,
    0x88, 0x11, 0x40, 0x63, 0x10, 0x1e, 0x58, 0xf,
    0x3b, 0xff, 0xa8, 0x1f, 0xfe, 0x60,

    /* U+0071 "q" */
    0x1, 0x3f, 0xf6, 0xb5, 0xfc, 0xc4, 0x60, 0x78,
    0xa4, 0x3, 0x98, 0x19, 0x28, 0x81, 0xff, 0x6b,
    0x6d, 0xd8, 0x1f, 0x89, 0x1, 0xdc, 0xf, 0xff,
    0xe1, 0x20, 0x3b, 0x81, 0xfd, 0xad, 0xb7, 0x60,
    0x73, 0x3, 0x25, 0x10, 0x3e, 0x8c, 0xf, 0x16,
    0x80, 0xf4, 0xff, 0xda, 0x60, 0x3f, 0xfd, 0x0,

    /* U+0072 "r" */
    0x0, 0xb7, 0xfd, 0x42, 0xa4, 0xf, 0xa0, 0x19,
    0x2b, 0x2, 0x5, 0xad, 0x98, 0x18, 0x90, 0x1f,
    0xff, 0xf0, 0x3f, 0x80,

    /* U+0073 "s" */
    0x0, 0xf7, 0xff, 0xc0, 0x24, 0x10, 0x3f, 0xc5,
    0x81, 0x25, 0xf8, 0x20, 0x27, 0x6f, 0xe0, 0x40,
    0x88, 0x1f, 0xc8, 0x9, 0x7f, 0xe8, 0x5, 0x40,
    0xfe, 0x74, 0x2, 0xf1, 0xa5, 0x80, 0x92, 0x1,
    0x39, 0x6f, 0x1, 0x60, 0x3f, 0xf8, 0x72, 0xdf,
    0xc0, 0x58, 0x34, 0xbe, 0x2, 0x28, 0xf, 0xf9,
    0xe0,

    /* U+0074 "t" */
    0x7, 0xfa, 0x81, 0xff, 0xd2, 0xd8, 0x4, 0xbf,
    0x80, 0xfe, 0xa8, 0xc, 0x91, 0xb4, 0x2, 0x56,
    0xa0, 0x1f, 0xfe, 0x22, 0x4, 0xc0, 0xe2, 0x0,
    0xeb, 0x0, 0x70, 0x22, 0x98, 0x3, 0x90, 0x18,

    /* U+0075 "u" */
    0x1f, 0xd8, 0xe, 0xdf, 0xc0, 0x7f, 0xff, 0xc0,
    0xff, 0xee, 0x90, 0x3f, 0x12, 0x2, 0x20, 0x78,
    0x81, 0x6b, 0x6c, 0x4, 0x40, 0x40, 0x32, 0x50,
    0x1b, 0x80, 0x54, 0x81, 0xf1, 0xc4, 0x0,

    /* U+0076 "v" */
    0xbf, 0xc4, 0xc, 0x7f, 0xaf, 0x2, 0xa0, 0x6a,
    0x5, 0xd0, 0x13, 0x3, 0x30, 0x24, 0x18, 0x12,
    0x0, 0x80, 0x98, 0xa, 0x5, 0xc0, 0x70, 0x2a,
    0x0, 0x90, 0x4, 0x1, 0x0, 0x24, 0x5, 0x40,
    0x9b, 0x1, 0x50, 0x33, 0x2, 0xb4, 0x4, 0xc0,
    0xe4, 0x0, 0x90, 0x4, 0x7, 0xb8, 0x1e, 0xe0,
    0x79, 0x1, 0xc5, 0x1, 0xf3, 0x3, 0x50, 0x3f,
    0x50, 0x33, 0x3, 0x0,

    /* U+0077 "w" */
    0x9f, 0xc8, 0xe, 0xff, 0x10, 0x3b, 0xfb, 0x50,
    0x2e, 0x6, 0x60, 0x6a, 0x6, 0x60, 0x50, 0x90,
    0x4, 0x6, 0xa0, 0x66, 0x6, 0xa0, 0x48, 0x50,
    0x26, 0x0, 0x90, 0x1c, 0x80, 0x22, 0x1, 0x80,
    0x60, 0x54, 0x5, 0x3, 0xdc, 0x7, 0x2, 0xa0,
    0x48, 0x1, 0x20, 0xc0, 0x88, 0x4, 0x1, 0x0,
    0x24, 0x5, 0xc0, 0xaa, 0x2, 0x74, 0x9, 0xb0,
    0x15, 0x3, 0x20, 0x27, 0x0, 0xab, 0x2, 0xb4,
    0x4, 0xc0, 0xe6, 0x4, 0x40, 0x22, 0x18, 0x2,
    0x40, 0x10, 0x1e, 0xa0, 0x7b, 0x80, 0xa0, 0x7b,
    0x81, 0xe2, 0x40, 0x72, 0x0, 0x48, 0xe, 0x40,
    0x7d, 0x40, 0xcc, 0xd, 0x40, 0xcc, 0xf, 0xcc,
    0xd, 0x40, 0xcc, 0xd, 0x40, 0xc0,

    /* U+0078 "x" */
    0x5f, 0xd4, 0xc, 0xff, 0xa8, 0x4c, 0x2, 0x80,
    0xc, 0x2, 0xa0, 0x21, 0x0, 0xd0, 0xe0, 0x58,
    0xd, 0xc0, 0xad, 0x10, 0x10, 0x81, 0x8d, 0x2,
    0x40, 0x13, 0x3, 0xc9, 0x81, 0xd4, 0xf, 0xd0,
    0xd, 0x0, 0xfe, 0x80, 0x68, 0x7, 0xe4, 0xc0,
    0xea, 0x7, 0x8d, 0x2, 0x40, 0x13, 0x3, 0xb8,
    0x15, 0xa2, 0x2, 0x10, 0x28, 0x40, 0x34, 0x38,
    0x16, 0x0, 0x98, 0x3, 0x0, 0x18, 0x5, 0x40,

    /* U+0079 "y" */
    0xbf, 0xc0, 0x73, 0xfe, 0x40, 0x7f, 0xff, 0xc0,
    0xff, 0xe0, 0x90, 0x3f, 0xf8, 0x3c, 0x80, 0x58,
    0xc, 0x40, 0x8e, 0xfd, 0x50, 0x1a, 0x10, 0x3f,
    0xf8, 0x3a, 0x25, 0x36, 0xac, 0xf, 0x3b, 0x69,
    0xb, 0x81, 0xff, 0xc1, 0xc0, 0x63, 0x27, 0xd5,
    0x1, 0x26, 0xff, 0x20, 0x2a, 0x7, 0xfc, 0x6a,
    0x0,

    /* U+007A "z" */
    0x7f, 0xff, 0xf0, 0x28, 0x1f, 0xfc, 0x22, 0x97,
    0xe0, 0x39, 0x5b, 0xf0, 0x1d, 0x40, 0xf9, 0xa0,
    0x2c, 0x7, 0xca, 0x1, 0x52, 0x7, 0x8d, 0x2,
    0x68, 0xf, 0xb8, 0x12, 0x80, 0x7d, 0x48, 0x3,
    0x40, 0xfa, 0x20, 0x2e, 0x7, 0x2b, 0x4c, 0x8,
    0xcb, 0x73, 0x29, 0x0, 0xc5, 0x2e, 0xc0, 0x7f,
    0xf0, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 230, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 115, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 178, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 23, .adv_w = 291, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 106, .adv_w = 102, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 113, .adv_w = 176, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 144, .adv_w = 176, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 174, .adv_w = 147, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 196, .adv_w = 248, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 224, .adv_w = 100, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 231, .adv_w = 286, .box_w = 13, .box_h = 3, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 240, .adv_w = 102, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 220, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 277, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 353, .adv_w = 98, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 280, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 281, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 501, .adv_w = 275, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 569, .adv_w = 280, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 629, .adv_w = 276, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 708, .adv_w = 276, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 778, .adv_w = 283, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 865, .adv_w = 276, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 946, .adv_w = 103, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 298, .box_w = 19, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1052, .adv_w = 292, .box_w = 18, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1126, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1170, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1223, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1292, .adv_w = 276, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1337, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1401, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1428, .adv_w = 98, .box_w = 4, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1432, .adv_w = 225, .box_w = 14, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1462, .adv_w = 276, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1538, .adv_w = 222, .box_w = 14, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1568, .adv_w = 325, .box_w = 19, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1632, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1701, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1749, .adv_w = 289, .box_w = 18, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1810, .adv_w = 285, .box_w = 17, .box_h = 19, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1873, .adv_w = 285, .box_w = 18, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1952, .adv_w = 280, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2026, .adv_w = 262, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2051, .adv_w = 285, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2086, .adv_w = 259, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2172, .adv_w = 457, .box_w = 29, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2323, .adv_w = 262, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2411, .adv_w = 260, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2469, .adv_w = 268, .box_w = 17, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2539, .adv_w = 261, .box_w = 16, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2581, .adv_w = 261, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2630, .adv_w = 239, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2665, .adv_w = 261, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2712, .adv_w = 239, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2765, .adv_w = 167, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2794, .adv_w = 261, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 2861, .adv_w = 239, .box_w = 15, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2890, .adv_w = 102, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2901, .adv_w = 103, .box_w = 8, .box_h = 21, .ofs_x = -2, .ofs_y = -4},
    {.bitmap_index = 2929, .adv_w = 239, .box_w = 15, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2982, .adv_w = 103, .box_w = 5, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2988, .adv_w = 362, .box_w = 21, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3032, .adv_w = 239, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3064, .adv_w = 239, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3113, .adv_w = 261, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 3167, .adv_w = 261, .box_w = 16, .box_h = 17, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 3215, .adv_w = 157, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3235, .adv_w = 228, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3284, .adv_w = 146, .box_w = 9, .box_h = 17, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3316, .adv_w = 239, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3347, .adv_w = 225, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3407, .adv_w = 387, .box_w = 24, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3509, .adv_w = 230, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3573, .adv_w = 250, .box_w = 14, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 3622, .adv_w = 228, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 4, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 39, .range_length = 20, .glyph_id_start = 5,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 25,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 26, .glyph_id_start = 51,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    25, 46,
    25, 72,
    57, 60,
    67, 60,
    75, 60
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -38, -38, 15, 38, 15
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 5,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 4,
    .bpp = 3,
    .kern_classes = 0,
    .bitmap_format = 1,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

////extern const lv_font_t LV_FONT_MONTSERRAT_24;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_XinYin_reg24 = {
#else
lv_font_t font_XinYin_reg24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_XINYIN_REG24*/

