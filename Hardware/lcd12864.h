/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:20 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-03-14 21:32:03
 */
#ifndef _LCD12864_H
#define _LCD12864_H

#include "stc12c5a60s2.h"

sbit lcd_bk         = P2^0; // background light
sbit lcd_clk        = P0^5; // E, serial model clock
sbit lcd_sda_out    = P0^4; // R/W, serial model data
sbit lcd_sda_in     = P0^4; // read sda data
sbit lcd_cs         = P0^3; // RS, serial model chip select, "1" is active

#define LCD_WRITE_CMD       0xf8
#define LCD_WRITE_DATA      0xfa
#define LCD_READ_STATE      0xfc
#define LCD_READ_DATA       0xfe   

#define DISP_CLR             0x01
#define RETURN_HOME          0x02
#define ENTRY_MODE           0x04
#define DISP_CTRL            0x08
#define DISP_CURSOR          0x10
#define FUNCTION_SET         0x20
#define CGRAM_ADDR           0x40
#define DDRAM_ADDR           0x80

#define STANDBY_MODE         0x01
#define SCROLL_CGRAM_ADDR    0x02
#define REVERSE              0x04
#define EXTENDED_FUNCTION    0x20
#define SCROLL_ADDR          0x40
#define GDRAM_ADDR           0x80

typedef enum LCD_BK_OFF_ON
{
    LCD_ON  = 0,
    LCD_OFF = 1
} LcdBk;

void lcd_init(void);
void lcd_bk_off_on(LcdBk state);
void lcd_write_data(unsigned char cmd, unsigned char w_data);
unsigned char lcd_read_data(void);

#endif
