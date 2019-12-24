/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:20 
 * @Last Modified by: luoqi
 * @Last Modified time: 2019-12-24 22:38:48
 */
#ifndef _LCD12864_H
#define _LCD12864_H

#include "stc12c5a60s2.h"

sbit LCD_BK  = P2^0; // background light
sbit LCD_clk = P0^5; // E, serial model clock
sbit LCD_sdi = P0^4; // R/W, serial model data
sbit LCD_cs  = P0^3; // RS, serial model chip select, "1" is active

typedef enum LCD_BK_OFF_ON
{
    LCD_ON  = 0,
    LCD_OFF = 1
} LcdBk;

typedef enum LCD_CMD
{
    LCD_WrCmd   = 0xf8,
    LCD_WrData  = 0xfa,
    LCD_RdState = 0xfc,
    LCD_RdData  = 0xfe
} LcdCmd;


void lcd_set_dot(unsigned char x, unsigned char y);

void lcd_write(LcdCmd cmd, unsigned char wdata);

#endif
