/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:24 
 * @Last Modified by: luoqi
 * @Last Modified time: 2019-12-24 22:38:47
 */
#include "lcd12864.h"
#include "delay.h"


void lcd_set_dot(unsigned char x, unsigned char y)
{
    
}

void lcd_write(LcdCmd cmd, unsigned char wdata)
{
    unsigned char i;
    unsigned char data_h_half;
    unsigned char data_l_half; 

    data_h_half = wdata & 0xf0;
    data_l_half = (wdata<<4) & 0xf0;

    LCD_clk = 0;
    LCD_cs  = 1;
    for(i=0; i<24; i++)
    {
        if(i<8)
        {
            LCD_sdi = ((cmd & 0x80) == 0x80);
            cmd = cmd << 1;
        }
        if(i>=8 && i<16)
        {
            LCD_sdi = ((data_h_half & 0x80) == 0x80);
            data_h_half = data_h_half << 1;
        }
        else
        {
            LCD_sdi = ((data_l_half & 0x80) == 0x80);
            data_l_half = data_l_half << 1;
        }
        LCD_clk = 1;
        delay_us(50);
        LCD_clk = 0;
    }
    LCD_cs = 0;
}

