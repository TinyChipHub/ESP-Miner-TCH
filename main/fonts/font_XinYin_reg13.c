/*******************************************************************************
 * Size: 13 px
 * Bpp: 4
 * Opts: --bpp 4 --size 13 --no-compress --font ZiTiQuanXinYiLOGOTi-2.ttf --range 32-127 --format lvgl -o font_XinYin_reg13.c
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


#ifndef FONT_XINYIN_REG13
#define FONT_XINYIN_REG13 1
#endif

#if FONT_XINYIN_REG13

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x1f, 0xf1, 0xff, 0x1f, 0xf1, 0xff, 0x1f, 0xf1,
    0xff, 0x8, 0x81, 0xff, 0x1f, 0xf0,

    /* U+0022 "\"" */
    0x1f, 0x98, 0xf2, 0x1f, 0x98, 0xf2, 0x1f, 0x98,
    0xf2, 0x1d, 0x76, 0xd1,

    /* U+0023 "#" */
    0x0, 0xf, 0xf0, 0xff, 0x0, 0x2, 0xfd, 0x1f,
    0xd0, 0x8, 0xff, 0xff, 0xff, 0xe0, 0x4a, 0xfb,
    0xaf, 0xb5, 0x1, 0x9f, 0x79, 0xf8, 0x10, 0xff,
    0xff, 0xff, 0xf8, 0x4, 0xef, 0x5e, 0xf6, 0x10,
    0xf, 0xf0, 0xff, 0x0, 0x0, 0x66, 0x6, 0x60,
    0x0,

    /* U+0027 "'" */
    0x1f, 0x81, 0xf8, 0x1f, 0x81, 0xd7,

    /* U+0028 "(" */
    0x5, 0xef, 0xf0, 0xf, 0xfa, 0x60, 0x1f, 0xf0,
    0x0, 0x1f, 0xf0, 0x0, 0x1f, 0xf0, 0x0, 0x1f,
    0xf0, 0x0, 0x1f, 0xf0, 0x0, 0xf, 0xf5, 0x10,
    0x9, 0xff, 0xf0, 0x0, 0x34, 0x40,

    /* U+0029 ")" */
    0x1f, 0xfe, 0x40, 0x6, 0xaf, 0xe0, 0x0, 0x1f,
    0xf0, 0x0, 0x1f, 0xf0, 0x0, 0x1f, 0xf0, 0x0,
    0x1f, 0xf0, 0x0, 0x1f, 0xf0, 0x1, 0x6f, 0xf0,
    0x1f, 0xff, 0x80, 0x4, 0x43, 0x0,

    /* U+002A "*" */
    0x4, 0xf3, 0x1, 0xcf, 0xc1, 0x2d, 0xfd, 0x10,
    0x2d, 0x10,

    /* U+002B "+" */
    0x0, 0x9, 0xa2, 0x0, 0x0, 0xd, 0xf3, 0x0,
    0x1, 0x1d, 0xf5, 0x10, 0x1f, 0xff, 0xff, 0xf7,
    0x4, 0x4e, 0xf7, 0x42, 0x0, 0xd, 0xf3, 0x0,
    0x0, 0xd, 0xf3, 0x0,

    /* U+002C "," */
    0x9, 0x41, 0xf7, 0x9, 0x20, 0x20,

    /* U+002D "-" */
    0x1, 0x11, 0x11, 0x10, 0x7f, 0xff, 0xff, 0xf1,
    0x24, 0x44, 0x44, 0x40,

    /* U+002E "." */
    0xa, 0x51, 0xf8,

    /* U+002F "/" */
    0x0, 0x0, 0x8f, 0x80, 0x0, 0xe, 0xf1, 0x0,
    0x6, 0xfa, 0x0, 0x0, 0xdf, 0x30, 0x0, 0x5f,
    0xc0, 0x0, 0xc, 0xf4, 0x0, 0x3, 0xfd, 0x0,
    0x0, 0xaf, 0x60, 0x0, 0x2f, 0xe0, 0x0, 0x0,

    /* U+0030 "0" */
    0xb, 0xff, 0xff, 0xfe, 0x38, 0xfe, 0x66, 0x6b,
    0xfd, 0x9f, 0x70, 0x0, 0x2f, 0xf9, 0xf7, 0x0,
    0x1, 0xff, 0x9f, 0x70, 0x0, 0x1f, 0xf9, 0xf7,
    0x0, 0x1, 0xff, 0x9f, 0x70, 0x0, 0x2f, 0xf8,
    0xfe, 0x66, 0x6b, 0xfd, 0xb, 0xff, 0xff, 0xfe,
    0x30,

    /* U+0031 "1" */
    0x6f, 0xb6, 0xfb, 0x6f, 0xb6, 0xfb, 0x6f, 0xb6,
    0xfb, 0x6f, 0xb6, 0xfb, 0x6f, 0xb0,

    /* U+0032 "2" */
    0xf, 0xff, 0xff, 0xfb, 0x10, 0x6, 0x66, 0x66,
    0xbf, 0xb0, 0x0, 0x0, 0x0, 0x1f, 0xf0, 0x0,
    0x1, 0x11, 0x7f, 0xd0, 0x8, 0xff, 0xff, 0xff,
    0x30, 0x5f, 0xe5, 0x44, 0x41, 0x0, 0x8f, 0x90,
    0x0, 0x0, 0x0, 0x4f, 0xf7, 0x66, 0x66, 0x40,
    0x6, 0xef, 0xff, 0xff, 0xa0,

    /* U+0033 "3" */
    0xbf, 0xff, 0xff, 0xfa, 0x0, 0x46, 0x66, 0x66,
    0xcf, 0x90, 0x0, 0x0, 0x0, 0x3f, 0xd0, 0x1,
    0x11, 0x11, 0x9f, 0xb0, 0x1f, 0xff, 0xff, 0xff,
    0x50, 0x4, 0x44, 0x44, 0x9f, 0xd0, 0x0, 0x0,
    0x0, 0xf, 0xf1, 0x46, 0x66, 0x66, 0xaf, 0xd0,
    0xbf, 0xff, 0xff, 0xfc, 0x20,

    /* U+0034 "4" */
    0x0, 0x2, 0xff, 0xfc, 0x0, 0x0, 0xa, 0xfc,
    0xfc, 0x0, 0x0, 0x3f, 0xd5, 0xfc, 0x0, 0x0,
    0xcf, 0x45, 0xfc, 0x0, 0x5, 0xfb, 0x5, 0xfc,
    0x0, 0x1e, 0xf4, 0x16, 0xfc, 0x10, 0xcf, 0xff,
    0xff, 0xff, 0xf1, 0x34, 0x44, 0x48, 0xfd, 0x40,
    0x0, 0x0, 0x5, 0xfc, 0x0,

    /* U+0035 "5" */
    0x9f, 0xff, 0xff, 0xff, 0x80, 0x9f, 0xb6, 0x66,
    0x66, 0x30, 0x9f, 0x80, 0x0, 0x0, 0x0, 0x8f,
    0xa1, 0x11, 0x10, 0x0, 0x6f, 0xff, 0xff, 0xfd,
    0x10, 0x3, 0x44, 0x44, 0xaf, 0xc0, 0x0, 0x0,
    0x0, 0x1f, 0xf0, 0x36, 0x66, 0x66, 0xbf, 0xb0,
    0x9f, 0xff, 0xff, 0xfb, 0x10,

    /* U+0036 "6" */
    0x4, 0xcf, 0xff, 0xff, 0x62, 0xff, 0xa6, 0x66,
    0x62, 0x8f, 0xb0, 0x0, 0x0, 0x9, 0xf8, 0x11,
    0x11, 0x0, 0x9f, 0xff, 0xff, 0xfc, 0x19, 0xfa,
    0x44, 0x4a, 0xfb, 0x8f, 0x90, 0x0, 0x2f, 0xe2,
    0xff, 0x96, 0x6c, 0xfa, 0x4, 0xdf, 0xff, 0xfb,
    0x0,

    /* U+0037 "7" */
    0xdf, 0xff, 0xff, 0xff, 0xf5, 0x66, 0x66, 0x69,
    0xfd, 0x0, 0x0, 0x0, 0xcf, 0x40, 0x0, 0x0,
    0x5f, 0xb0, 0x0, 0x0, 0xe, 0xf2, 0x0, 0x0,
    0x9, 0xf8, 0x0, 0x0, 0x2, 0xfe, 0x0, 0x0,
    0x0, 0xcf, 0x50, 0x0, 0x0, 0x5f, 0xb0, 0x0,
    0x0,

    /* U+0038 "8" */
    0x4, 0xdf, 0xff, 0xfb, 0x0, 0x1f, 0xf8, 0x66,
    0xcf, 0xa0, 0x5f, 0xc0, 0x0, 0x2f, 0xf0, 0x3f,
    0xf3, 0x11, 0x8f, 0xc0, 0xd, 0xff, 0xff, 0xff,
    0x70, 0x5f, 0xe5, 0x44, 0x8f, 0xe0, 0x9f, 0x80,
    0x0, 0xe, 0xf2, 0x5f, 0xe7, 0x66, 0x9f, 0xe0,
    0x7, 0xef, 0xff, 0xfd, 0x20,

    /* U+0039 "9" */
    0x6, 0xef, 0xff, 0xe8, 0x4, 0xff, 0x76, 0x7e,
    0xf7, 0x9f, 0x80, 0x0, 0x3f, 0xe6, 0xfd, 0x31,
    0x13, 0xff, 0xb, 0xff, 0xff, 0xff, 0xf0, 0x2,
    0x44, 0x46, 0xff, 0x0, 0x0, 0x0, 0x5f, 0xe0,
    0x66, 0x66, 0x7f, 0xf7, 0xf, 0xff, 0xff, 0xe8,
    0x0,

    /* U+003A ":" */
    0x1a, 0x61, 0xf9, 0x0, 0x0, 0xa5, 0x1f, 0x90,

    /* U+0041 "A" */
    0x0, 0x5, 0xff, 0x60, 0x0, 0x0, 0xb, 0xff,
    0xd0, 0x0, 0x0, 0x2f, 0xed, 0xf3, 0x0, 0x0,
    0x9f, 0x76, 0xfa, 0x0, 0x0, 0xff, 0x10, 0xef,
    0x10, 0x6, 0xfa, 0x0, 0x8f, 0x80, 0xd, 0xf3,
    0x0, 0x2f, 0xe0, 0x4f, 0xe6, 0x62, 0xb, 0xf5,
    0xbf, 0xff, 0xfb, 0x4, 0xfc,

    /* U+0042 "B" */
    0x7f, 0xff, 0xff, 0xfc, 0x10, 0x7f, 0xc6, 0x66,
    0xbf, 0xc0, 0x7f, 0x90, 0x0, 0xf, 0xf1, 0x7f,
    0xa1, 0x11, 0x6f, 0xe0, 0x7f, 0xff, 0xff, 0xff,
    0x90, 0x7f, 0xb4, 0x44, 0x6f, 0xf1, 0x7f, 0x90,
    0x0, 0xc, 0xf4, 0x7f, 0xc6, 0x66, 0x8f, 0xf1,
    0x7f, 0xff, 0xff, 0xfd, 0x30,

    /* U+0043 "C" */
    0x4, 0xef, 0xff, 0xff, 0xf1, 0x2f, 0xf8, 0x66,
    0x66, 0x60, 0x7f, 0xa0, 0x0, 0x0, 0x0, 0x7f,
    0xa0, 0x0, 0x0, 0x0, 0x7f, 0xa0, 0x0, 0x0,
    0x0, 0x7f, 0xa0, 0x0, 0x0, 0x0, 0x7f, 0xb0,
    0x0, 0x0, 0x0, 0x2f, 0xf8, 0x66, 0x66, 0x60,
    0x4, 0xef, 0xff, 0xff, 0xf1,

    /* U+0044 "D" */
    0x7f, 0xff, 0xff, 0xe9, 0x0, 0x7f, 0xc6, 0x67,
    0xef, 0x90, 0x7f, 0x90, 0x0, 0x2f, 0xf0, 0x7f,
    0x90, 0x0, 0xf, 0xf1, 0x7f, 0x90, 0x0, 0xf,
    0xf1, 0x7f, 0x90, 0x0, 0xf, 0xf1, 0x7f, 0x90,
    0x0, 0x3f, 0xf0, 0x7f, 0xc6, 0x67, 0xef, 0x90,
    0x7f, 0xff, 0xff, 0xe9, 0x0,

    /* U+0045 "E" */
    0x2, 0xcf, 0xff, 0xff, 0xf1, 0x1e, 0xfb, 0x66,
    0x66, 0x60, 0x6f, 0xc0, 0x0, 0x0, 0x0, 0x7f,
    0xa1, 0x11, 0x11, 0x10, 0x7f, 0xff, 0xff, 0xff,
    0xf1, 0x7f, 0xb4, 0x44, 0x44, 0x40, 0x6f, 0xc0,
    0x0, 0x0, 0x0, 0x1e, 0xfa, 0x66, 0x66, 0x60,
    0x2, 0xcf, 0xff, 0xff, 0xf1,

    /* U+0046 "F" */
    0x2, 0xcf, 0xff, 0xff, 0xf1, 0x1e, 0xfb, 0x66,
    0x66, 0x60, 0x6f, 0xd0, 0x0, 0x0, 0x0, 0x7f,
    0x90, 0x0, 0x0, 0x0, 0x7f, 0xa1, 0x11, 0x11,
    0x10, 0x7f, 0xff, 0xff, 0xff, 0xf1, 0x7f, 0xb4,
    0x44, 0x44, 0x40, 0x7f, 0x90, 0x0, 0x0, 0x0,
    0x7f, 0x90, 0x0, 0x0, 0x0,

    /* U+0047 "G" */
    0x1, 0xbf, 0xff, 0xff, 0xf1, 0xd, 0xfc, 0x66,
    0x66, 0x60, 0x5f, 0xd0, 0x0, 0x0, 0x0, 0x7f,
    0xa0, 0x0, 0x0, 0x10, 0x7f, 0xa0, 0x0, 0xf,
    0xf1, 0x7f, 0xa0, 0x0, 0xf, 0xf1, 0x5f, 0xd0,
    0x0, 0xf, 0xf1, 0xd, 0xfc, 0x76, 0x6f, 0xf1,
    0x1, 0xbf, 0xff, 0xff, 0xf1,

    /* U+0048 "H" */
    0x7f, 0x90, 0x0, 0xf, 0xf1, 0x7f, 0x90, 0x0,
    0xf, 0xf1, 0x7f, 0x90, 0x0, 0xf, 0xf1, 0x7f,
    0xa1, 0x11, 0x1f, 0xf1, 0x7f, 0xff, 0xff, 0xff,
    0xf1, 0x7f, 0xb4, 0x44, 0x4f, 0xf1, 0x7f, 0x90,
    0x0, 0xf, 0xf1, 0x7f, 0x90, 0x0, 0xf, 0xf1,
    0x7f, 0x90, 0x0, 0xf, 0xf1,

    /* U+0049 "I" */
    0x6f, 0xb6, 0xfb, 0x6f, 0xb6, 0xfb, 0x6f, 0xb6,
    0xfb, 0x6f, 0xb6, 0xfb, 0x6f, 0xb0,

    /* U+004A "J" */
    0x0, 0x0, 0xf, 0xf1, 0x0, 0x0, 0xf, 0xf1,
    0x0, 0x0, 0xf, 0xf1, 0x0, 0x0, 0xf, 0xf1,
    0x0, 0x0, 0xf, 0xf1, 0x0, 0x0, 0xf, 0xf1,
    0x0, 0x0, 0x3f, 0xf0, 0x46, 0x67, 0xef, 0x90,
    0xbf, 0xff, 0xe8, 0x0,

    /* U+004B "K" */
    0x7f, 0xa0, 0x0, 0xcf, 0xa0, 0x7f, 0xa0, 0xb,
    0xfc, 0x0, 0x7f, 0xa0, 0x9f, 0xd1, 0x0, 0x7f,
    0xa7, 0xfe, 0x10, 0x0, 0x7f, 0xcf, 0xf5, 0x0,
    0x0, 0x7f, 0xa7, 0xfe, 0x10, 0x0, 0x7f, 0xa0,
    0x9f, 0xd1, 0x0, 0x7f, 0xa0, 0xb, 0xfc, 0x0,
    0x7f, 0xa0, 0x0, 0xcf, 0xa0,

    /* U+004C "L" */
    0x7f, 0xa0, 0x0, 0x0, 0x7f, 0xa0, 0x0, 0x0,
    0x7f, 0xa0, 0x0, 0x0, 0x7f, 0xa0, 0x0, 0x0,
    0x7f, 0xa0, 0x0, 0x0, 0x7f, 0xa0, 0x0, 0x0,
    0x6f, 0xc0, 0x0, 0x0, 0x1e, 0xfa, 0x66, 0x61,
    0x2, 0xcf, 0xff, 0xf4,

    /* U+004D "M" */
    0x6f, 0xe1, 0x0, 0x1, 0xef, 0x66, 0xff, 0xb0,
    0x0, 0xaf, 0xf6, 0x6f, 0xff, 0x50, 0x5f, 0xff,
    0x66, 0xfc, 0xee, 0x2e, 0xfc, 0xf6, 0x6f, 0xb5,
    0xff, 0xf6, 0xbf, 0x66, 0xfb, 0x9, 0xca, 0xb,
    0xf6, 0x6f, 0xb0, 0x0, 0x0, 0xbf, 0x66, 0xfb,
    0x0, 0x0, 0xb, 0xf6, 0x6f, 0xb0, 0x0, 0x0,
    0xbf, 0x60,

    /* U+004E "N" */
    0x7f, 0xe1, 0x0, 0xf, 0xf1, 0x7f, 0xfb, 0x0,
    0xf, 0xf1, 0x7f, 0xff, 0x60, 0xf, 0xf1, 0x7f,
    0xae, 0xf2, 0xf, 0xf1, 0x7f, 0x93, 0xfd, 0xf,
    0xf1, 0x7f, 0x90, 0x7f, 0x9f, 0xf1, 0x7f, 0x90,
    0xc, 0xff, 0xf1, 0x7f, 0x90, 0x1, 0xef, 0xf1,
    0x7f, 0x90, 0x0, 0x5f, 0xf1,

    /* U+004F "O" */
    0x9, 0xff, 0xff, 0xfe, 0x50, 0x5f, 0xf7, 0x66,
    0xaf, 0xf0, 0x7f, 0xa0, 0x0, 0xf, 0xf1, 0x7f,
    0x90, 0x0, 0xf, 0xf1, 0x7f, 0x90, 0x0, 0xf,
    0xf1, 0x7f, 0x90, 0x0, 0xf, 0xf1, 0x7f, 0xa0,
    0x0, 0xf, 0xf1, 0x5f, 0xf7, 0x66, 0xaf, 0xf0,
    0x9, 0xff, 0xff, 0xfe, 0x50,

    /* U+0050 "P" */
    0x7f, 0xff, 0xff, 0xfb, 0x20, 0x7f, 0xc6, 0x66,
    0xbf, 0xd0, 0x7f, 0x90, 0x0, 0xe, 0xf4, 0x7f,
    0x90, 0x0, 0xd, 0xf4, 0x7f, 0xa1, 0x11, 0x6f,
    0xf1, 0x7f, 0xff, 0xff, 0xff, 0x50, 0x7f, 0xb4,
    0x44, 0x41, 0x0, 0x7f, 0x90, 0x0, 0x0, 0x0,
    0x7f, 0x90, 0x0, 0x0, 0x0,

    /* U+0051 "Q" */
    0x9, 0xff, 0xff, 0xfe, 0x50, 0x5f, 0xf7, 0x66,
    0xaf, 0xf0, 0x7f, 0xa0, 0x0, 0xf, 0xf1, 0x7f,
    0x90, 0x0, 0xf, 0xf1, 0x7f, 0x90, 0x0, 0xf,
    0xf1, 0x7f, 0x90, 0x0, 0xf, 0xf1, 0x7f, 0xa0,
    0x2, 0xcf, 0xf1, 0x5f, 0xf7, 0x68, 0xff, 0xf0,
    0xa, 0xff, 0xff, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x1, 0x30,

    /* U+0052 "R" */
    0x7f, 0xff, 0xff, 0xfb, 0x20, 0x7f, 0xc6, 0x66,
    0xbf, 0xd0, 0x7f, 0xa0, 0x0, 0xe, 0xf4, 0x7f,
    0xa0, 0x0, 0xc, 0xf4, 0x7f, 0xa1, 0x11, 0x6f,
    0xf1, 0x7f, 0xff, 0xff, 0xff, 0x50, 0x7f, 0xb4,
    0x44, 0xef, 0x20, 0x7f, 0xa0, 0x0, 0x7f, 0x90,
    0x7f, 0xa0, 0x0, 0xe, 0xf1,

    /* U+0053 "S" */
    0x6, 0xef, 0xff, 0xff, 0x80, 0x4f, 0xf7, 0x66,
    0x66, 0x30, 0x8f, 0x90, 0x0, 0x0, 0x0, 0x6f,
    0xd2, 0x11, 0x10, 0x0, 0xb, 0xff, 0xff, 0xfd,
    0x10, 0x0, 0x34, 0x44, 0xaf, 0xc0, 0x0, 0x0,
    0x0, 0x1f, 0xf0, 0x16, 0x66, 0x66, 0xbf, 0xb0,
    0x3f, 0xff, 0xff, 0xfb, 0x10,

    /* U+0054 "T" */
    0xdf, 0xff, 0xff, 0xff, 0xb5, 0x66, 0xcf, 0xb6,
    0x64, 0x0, 0x9, 0xf7, 0x0, 0x0, 0x0, 0x9f,
    0x70, 0x0, 0x0, 0x9, 0xf7, 0x0, 0x0, 0x0,
    0x9f, 0x70, 0x0, 0x0, 0x9, 0xf7, 0x0, 0x0,
    0x0, 0x9f, 0x70, 0x0, 0x0, 0x9, 0xf7, 0x0,
    0x0,

    /* U+0055 "U" */
    0x7f, 0xa0, 0x0, 0xf, 0xf2, 0x7f, 0xa0, 0x0,
    0xf, 0xf2, 0x7f, 0xa0, 0x0, 0xf, 0xf2, 0x7f,
    0xa0, 0x0, 0xf, 0xf2, 0x7f, 0xa0, 0x0, 0xf,
    0xf2, 0x7f, 0xa0, 0x0, 0xf, 0xf2, 0x7f, 0xa0,
    0x0, 0xf, 0xf1, 0x5f, 0xf7, 0x66, 0xaf, 0xf0,
    0xa, 0xff, 0xff, 0xfe, 0x50,

    /* U+0056 "V" */
    0xbf, 0x50, 0x0, 0x9f, 0x85, 0xfb, 0x0, 0xe,
    0xf2, 0xf, 0xf1, 0x4, 0xfc, 0x0, 0xaf, 0x70,
    0xaf, 0x60, 0x4, 0xfd, 0xf, 0xf1, 0x0, 0xe,
    0xf9, 0xfb, 0x0, 0x0, 0x8f, 0xff, 0x50, 0x0,
    0x3, 0xff, 0xf0, 0x0, 0x0, 0xd, 0xf9, 0x0,
    0x0,

    /* U+0057 "W" */
    0xaf, 0x70, 0x0, 0x7f, 0xe0, 0x0, 0xf, 0xf1,
    0x4f, 0xd0, 0x0, 0xdf, 0xf5, 0x0, 0x5f, 0xb0,
    0xe, 0xf2, 0x3, 0xff, 0xfa, 0x0, 0xbf, 0x60,
    0x8, 0xf8, 0x9, 0xf9, 0xff, 0x11, 0xff, 0x0,
    0x3, 0xfe, 0xe, 0xf2, 0xbf, 0x67, 0xfa, 0x0,
    0x0, 0xdf, 0x9f, 0xc0, 0x5f, 0xcc, 0xf4, 0x0,
    0x0, 0x7f, 0xff, 0x60, 0xe, 0xff, 0xe0, 0x0,
    0x0, 0x1f, 0xff, 0x10, 0x9, 0xff, 0x90, 0x0,
    0x0, 0xb, 0xfb, 0x0, 0x3, 0xff, 0x30, 0x0,

    /* U+0058 "X" */
    0x8f, 0xc0, 0x0, 0xef, 0x50, 0xcf, 0x80, 0xaf,
    0xa0, 0x2, 0xff, 0x8f, 0xe1, 0x0, 0x6, 0xff,
    0xf4, 0x0, 0x0, 0xe, 0xfc, 0x0, 0x0, 0x6,
    0xff, 0xf4, 0x0, 0x2, 0xff, 0x8f, 0xe1, 0x0,
    0xcf, 0x80, 0xaf, 0xa0, 0x8f, 0xc0, 0x0, 0xef,
    0x50,

    /* U+0059 "Y" */
    0x8f, 0x80, 0x0, 0xbf, 0x50, 0xcf, 0x40, 0x7f,
    0x90, 0x2, 0xfe, 0x4f, 0xd0, 0x0, 0x5, 0xff,
    0xf3, 0x0, 0x0, 0xb, 0xf8, 0x0, 0x0, 0x0,
    0xaf, 0x70, 0x0, 0x0, 0xa, 0xf7, 0x0, 0x0,
    0x0, 0xaf, 0x70, 0x0, 0x0, 0xa, 0xf7, 0x0,
    0x0,

    /* U+005A "Z" */
    0xcf, 0xff, 0xff, 0xff, 0xd5, 0x66, 0x66, 0x6e,
    0xfb, 0x0, 0x0, 0x8, 0xfe, 0x10, 0x0, 0x5,
    0xff, 0x30, 0x0, 0x3, 0xff, 0x50, 0x0, 0x1,
    0xef, 0x80, 0x0, 0x0, 0xcf, 0xb0, 0x0, 0x5,
    0xaf, 0xf7, 0x66, 0x65, 0xcf, 0xff, 0xff, 0xff,
    0xd0,

    /* U+0061 "a" */
    0x1c, 0xff, 0xfd, 0xef, 0x56, 0xff, 0x76, 0x9f,
    0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xf9, 0x0,
    0xc, 0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x56, 0xff,
    0x76, 0x9f, 0xf5, 0x1c, 0xff, 0xfd, 0xef, 0x50,

    /* U+0062 "b" */
    0x8f, 0x90, 0x0, 0x0, 0x8, 0xf9, 0x0, 0x0,
    0x0, 0x8f, 0xdd, 0xff, 0xfa, 0x8, 0xfe, 0x86,
    0x8f, 0xf3, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xf9,
    0x0, 0xc, 0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x58,
    0xfe, 0x86, 0x8f, 0xf3, 0x8f, 0xde, 0xff, 0xfa,
    0x0,

    /* U+0063 "c" */
    0xa, 0xff, 0xff, 0xf9, 0x6f, 0xf7, 0x66, 0x63,
    0x7f, 0x90, 0x0, 0x0, 0x8f, 0x90, 0x0, 0x0,
    0x7f, 0x90, 0x0, 0x0, 0x6f, 0xf7, 0x66, 0x63,
    0xa, 0xff, 0xff, 0xf9,

    /* U+0064 "d" */
    0x0, 0x0, 0x0, 0xcf, 0x50, 0x0, 0x0, 0xc,
    0xf5, 0x1c, 0xff, 0xfd, 0xef, 0x56, 0xff, 0x76,
    0x9f, 0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xf9,
    0x0, 0xc, 0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x56,
    0xff, 0x76, 0x9f, 0xf5, 0x1c, 0xff, 0xfd, 0xef,
    0x50,

    /* U+0065 "e" */
    0x8, 0xff, 0xff, 0xe3, 0x5f, 0xe7, 0x6c, 0xf9,
    0x7f, 0xa1, 0x1a, 0xf9, 0x8f, 0xff, 0xff, 0xf6,
    0x7f, 0xb4, 0x44, 0x30, 0x5f, 0xe6, 0x66, 0x62,
    0x9, 0xff, 0xff, 0xf7,

    /* U+0066 "f" */
    0x0, 0x9f, 0xf0, 0x4, 0xfe, 0x60, 0x6f, 0xff,
    0xf0, 0x2a, 0xfd, 0x70, 0x6, 0xfb, 0x0, 0x6,
    0xfb, 0x0, 0x6, 0xfb, 0x0, 0x6, 0xfb, 0x0,
    0x6, 0xfb, 0x0,

    /* U+0067 "g" */
    0x1c, 0xff, 0xeb, 0xef, 0x56, 0xff, 0x77, 0xbf,
    0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xf9, 0x0,
    0xc, 0xf5, 0x7f, 0xd2, 0x26, 0xef, 0x52, 0xff,
    0xff, 0xff, 0xf5, 0x1, 0x44, 0x30, 0xcf, 0x51,
    0x66, 0x66, 0x7f, 0xf2, 0x3f, 0xff, 0xff, 0xf6,
    0x0,

    /* U+0068 "h" */
    0x8f, 0x90, 0x0, 0x0, 0x8f, 0x90, 0x0, 0x0,
    0x8f, 0xee, 0xff, 0xc1, 0x8f, 0xd7, 0x7e, 0xf8,
    0x8f, 0x90, 0x8, 0xf9, 0x8f, 0x90, 0x7, 0xf9,
    0x8f, 0x90, 0x7, 0xf9, 0x8f, 0x90, 0x7, 0xf9,
    0x8f, 0x90, 0x7, 0xf9,

    /* U+0069 "i" */
    0x5f, 0xc5, 0xfc, 0x28, 0x65, 0xfc, 0x5f, 0xc5,
    0xfc, 0x5f, 0xc5, 0xfc, 0x5f, 0xc0,

    /* U+006A "j" */
    0x0, 0x5f, 0xc0, 0x5, 0xfc, 0x0, 0x27, 0x60,
    0x5, 0xfc, 0x0, 0x5f, 0xc0, 0x5, 0xfc, 0x0,
    0x5f, 0xc0, 0x5, 0xfc, 0x0, 0x5f, 0xc0, 0x6c,
    0xfa, 0x1f, 0xfc, 0x10,

    /* U+006B "k" */
    0x8f, 0x90, 0x0, 0x0, 0x8f, 0x90, 0x0, 0x0,
    0x8f, 0x90, 0x7f, 0xe1, 0x8f, 0x92, 0xff, 0x60,
    0x8f, 0x9c, 0xfb, 0x0, 0x8f, 0xdf, 0xf4, 0x0,
    0x8f, 0x99, 0xfd, 0x0, 0x8f, 0x90, 0xcf, 0xb0,
    0x8f, 0x90, 0x1e, 0xf8,

    /* U+006C "l" */
    0x5f, 0xc5, 0xfc, 0x5f, 0xc5, 0xfc, 0x5f, 0xc5,
    0xfc, 0x5f, 0xc5, 0xfc, 0x5f, 0xc0,

    /* U+006D "m" */
    0x8, 0xff, 0xfc, 0xaf, 0xff, 0xb0, 0x4f, 0xf7,
    0x9f, 0xfb, 0x6e, 0xf8, 0x6f, 0xb0, 0xf, 0xf3,
    0x7, 0xfa, 0x6f, 0xb0, 0xe, 0xf2, 0x7, 0xfa,
    0x6f, 0xb0, 0xe, 0xf2, 0x7, 0xfa, 0x6f, 0xb0,
    0xe, 0xf2, 0x7, 0xfa, 0x6f, 0xb0, 0xe, 0xf2,
    0x7, 0xfa,

    /* U+006E "n" */
    0xa, 0xff, 0xff, 0xb0, 0x6f, 0xf7, 0x7e, 0xf7,
    0x7f, 0x90, 0x8, 0xf9, 0x8f, 0x90, 0x8, 0xf9,
    0x8f, 0x90, 0x8, 0xf9, 0x8f, 0x90, 0x8, 0xf9,
    0x8f, 0x90, 0x8, 0xf9,

    /* U+006F "o" */
    0xa, 0xff, 0xff, 0xb0, 0x6f, 0xf7, 0x7e, 0xf7,
    0x7f, 0x90, 0x8, 0xf9, 0x8f, 0x90, 0x8, 0xf9,
    0x7f, 0x90, 0x8, 0xf9, 0x6f, 0xf7, 0x7e, 0xf7,
    0xa, 0xff, 0xff, 0xb0,

    /* U+0070 "p" */
    0x8f, 0xdd, 0xff, 0xfa, 0x8, 0xfe, 0x86, 0x8f,
    0xf3, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xf9, 0x0,
    0xc, 0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xfe,
    0x96, 0x8f, 0xf3, 0x8f, 0xdd, 0xff, 0xfa, 0x8,
    0xf9, 0x0, 0x0, 0x0, 0x8f, 0x90, 0x0, 0x0,
    0x0,

    /* U+0071 "q" */
    0x1c, 0xff, 0xfd, 0xef, 0x56, 0xff, 0x76, 0x9f,
    0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x58, 0xf9, 0x0,
    0xc, 0xf5, 0x8f, 0x90, 0x0, 0xcf, 0x56, 0xff,
    0x76, 0x9e, 0xf5, 0x1c, 0xff, 0xfd, 0xef, 0x50,
    0x0, 0x0, 0xc, 0xf5, 0x0, 0x0, 0x0, 0xcf,
    0x50,

    /* U+0072 "r" */
    0xa, 0xff, 0xf3, 0x6f, 0xf7, 0x61, 0x7f, 0x90,
    0x0, 0x8f, 0x90, 0x0, 0x8f, 0x90, 0x0, 0x8f,
    0x90, 0x0, 0x8f, 0x90, 0x0,

    /* U+0073 "s" */
    0xb, 0xff, 0xff, 0xf1, 0x8f, 0xc6, 0x66, 0x60,
    0xaf, 0x91, 0x11, 0x0, 0x3f, 0xff, 0xff, 0xa0,
    0x1, 0x44, 0x5e, 0xf4, 0x26, 0x66, 0x6e, 0xf4,
    0x6f, 0xff, 0xff, 0x80,

    /* U+0074 "t" */
    0xf, 0xf1, 0x0, 0xff, 0x10, 0xef, 0xff, 0xd5,
    0xff, 0x75, 0xf, 0xf1, 0x0, 0xff, 0x10, 0xf,
    0xf1, 0x0, 0xdf, 0xa5, 0x3, 0xdf, 0xd0,

    /* U+0075 "u" */
    0x8f, 0x90, 0x8, 0xf9, 0x8f, 0x90, 0x8, 0xf9,
    0x8f, 0x90, 0x8, 0xf9, 0x8f, 0x90, 0x8, 0xf9,
    0x7f, 0x90, 0x8, 0xf9, 0x6f, 0xf7, 0x7e, 0xf7,
    0xa, 0xff, 0xff, 0xb0,

    /* U+0076 "v" */
    0xcf, 0x50, 0xb, 0xf5, 0x5f, 0xb0, 0x2f, 0xe0,
    0xf, 0xf1, 0x8f, 0x90, 0x9, 0xf8, 0xef, 0x20,
    0x3, 0xff, 0xfc, 0x0, 0x0, 0xdf, 0xf6, 0x0,
    0x0, 0x7f, 0xf0, 0x0,

    /* U+0077 "w" */
    0xbf, 0x60, 0xb, 0xfc, 0x0, 0x4f, 0xc5, 0xfc,
    0x1, 0xff, 0xf2, 0xb, 0xf6, 0xe, 0xf2, 0x7f,
    0xff, 0x81, 0xff, 0x0, 0x8f, 0x8d, 0xf6, 0xfe,
    0x7f, 0x90, 0x2, 0xff, 0xfd, 0xc, 0xff, 0xf3,
    0x0, 0xc, 0xff, 0x70, 0x6f, 0xfd, 0x0, 0x0,
    0x6f, 0xf1, 0x1, 0xff, 0x70, 0x0,

    /* U+0078 "x" */
    0x7f, 0xb0, 0x1e, 0xf4, 0xb, 0xf8, 0xbf, 0x70,
    0x1, 0xef, 0xfb, 0x0, 0x0, 0x6f, 0xf2, 0x0,
    0x1, 0xef, 0xfb, 0x0, 0xb, 0xf8, 0xbf, 0x70,
    0x7f, 0xb0, 0x1e, 0xf4,

    /* U+0079 "y" */
    0x5f, 0xc0, 0x5, 0xfc, 0x5f, 0xc0, 0x5, 0xfc,
    0x5f, 0xc0, 0x5, 0xfc, 0x5f, 0xc0, 0x5, 0xfc,
    0x4f, 0xf3, 0x28, 0xfc, 0x1e, 0xff, 0xff, 0xfc,
    0x1, 0x44, 0x46, 0xfc, 0x6, 0x66, 0x6c, 0xfa,
    0x1f, 0xff, 0xff, 0xc1,

    /* U+007A "z" */
    0xaf, 0xff, 0xff, 0xf6, 0x46, 0x66, 0x9f, 0xf4,
    0x0, 0x1, 0xef, 0x80, 0x0, 0xc, 0xfb, 0x0,
    0x0, 0x9f, 0xd0, 0x0, 0x49, 0xff, 0x86, 0x62,
    0xaf, 0xff, 0xff, 0xf6
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 125, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 62, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 97, .box_w = 6, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 26, .adv_w = 158, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 55, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 73, .adv_w = 95, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 103, .adv_w = 95, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 133, .adv_w = 79, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 143, .adv_w = 134, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 171, .adv_w = 54, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 177, .adv_w = 155, .box_w = 8, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 189, .adv_w = 55, .box_w = 3, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 119, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 150, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 265, .adv_w = 53, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 151, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 152, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 149, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 414, .adv_w = 151, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 150, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 150, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 586, .adv_w = 150, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 56, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 635, .adv_w = 161, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 158, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 860, .adv_w = 150, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 950, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 995, .adv_w = 53, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 122, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1045, .adv_w = 149, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1090, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1126, .adv_w = 176, .box_w = 11, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1176, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1221, .adv_w = 154, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1266, .adv_w = 156, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1311, .adv_w = 154, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1361, .adv_w = 155, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1406, .adv_w = 151, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1451, .adv_w = 142, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1492, .adv_w = 155, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1537, .adv_w = 140, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1578, .adv_w = 248, .box_w = 16, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1650, .adv_w = 142, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1691, .adv_w = 141, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1732, .adv_w = 145, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1773, .adv_w = 141, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1805, .adv_w = 141, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1846, .adv_w = 130, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1874, .adv_w = 141, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1915, .adv_w = 130, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1943, .adv_w = 90, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1970, .adv_w = 141, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2011, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2047, .adv_w = 55, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2061, .adv_w = 56, .box_w = 5, .box_h = 11, .ofs_x = -2, .ofs_y = -2},
    {.bitmap_index = 2089, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2125, .adv_w = 56, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2139, .adv_w = 196, .box_w = 12, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2181, .adv_w = 130, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2209, .adv_w = 130, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2237, .adv_w = 141, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2278, .adv_w = 141, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2319, .adv_w = 85, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2340, .adv_w = 123, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2368, .adv_w = 79, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2391, .adv_w = 130, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2419, .adv_w = 122, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2447, .adv_w = 209, .box_w = 13, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2493, .adv_w = 125, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2521, .adv_w = 135, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2557, .adv_w = 124, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0}
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
    -21, -21, 8, 21, 8
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
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_XinYin_reg13 = {
#else
lv_font_t font_XinYin_reg13 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_XINYIN_REG13*/

