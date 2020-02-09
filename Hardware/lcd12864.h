/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:20 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-01-08 01:01:31
 */
#ifndef _LCD12864_H
#define _LCD12864_H

#include "stc12c5a60s2.h"

sbit LCD_BK  = P2^0; // background light
sbit LCD_clk = P0^5; // E, serial model clock
sbit LCD_sdi = P0^4; // R/W, serial model data
sbit LCD_cs  = P0^3; // RS, serial model chip select, "1" is active

#define DISPCLR             0x01
#define RETURNHOME          0x02
#define ENTRYMODE           0x04
#define DISPCTRL            0x08
#define DISPCURSOR          0x10
#define FUNCTIONSET         0x20
#define CGRAMADDR           0x40
#define DDRAMADDR           0x80

#define STANDBYMODE         0x01
#define SCROLLCGRAMADDR     0x02
#define REVERSE             0x04
#define EXTENDEDFUNCTION    0x20
#define SCROLLADDR          0x40
#define GDRAMADDR           0x80

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


void lcd_init(void);
void lcd_bk_off_on(LcdBk state);
void lcd_set_dot(unsigned char x, unsigned char y);
void lcd_put_str(unsigned char row, unsigned char col, unsigned char *puts);

unsigned char lcd_chek_busy(void);
unsigned char lcd_rw(LcdCmd cmd, unsigned char wdata);

#endif
