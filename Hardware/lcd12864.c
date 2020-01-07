/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:24 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-01-08 01:01:25
 */
#include "lcd12864.h"
#include "delay.h"

unsigned char code AC_TABLE[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,    //第一行汉字位置  
    0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,    //第二行汉字位置  
    0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,    //第三行汉字位置 
    0x98,0x99,0x9a,0x9b,0x9c,0x9d,0x9e,0x9f,    //第四行汉字位置 
};

void lcd_init()
{
    lcd_bk_off_on(LCD_ON);
    delay_ms(40);
    lcd_write(LCD_WrCmd, 0x30);
    delay_ms(40);
    lcd_write(LCD_WrCmd, 0x03);
    delay_ms(40);
    lcd_write(LCD_WrCmd, 0x0c);
    delay_ms(40);
    lcd_write(LCD_WrCmd, 0x01);
    delay_ms(40);
    lcd_write(LCD_WrCmd, 0x06);
    delay_ms(40);
}

void lcd_bk_off_on(LcdBk state)
{
    LCD_BK = state;
}

void lcd_set_dot(unsigned char x, unsigned char y)
{

}

void lcd_put_str(unsigned char row, unsigned char col, unsigned char *puts)
{
     lcd_write(LCD_WrCmd, 0x30);     
     lcd_write(LCD_WrCmd, AC_TABLE[8*row+col]);   
     while(*puts != '\0')      
     {
           if(col==8)           
           {            
                 col='0';
                 row++;
           }
           if(row==4) row='0';     
           lcd_write(LCD_WrCmd, AC_TABLE[8*row+col]);
           lcd_write(LCD_WrData, *puts);      
           puts++;
           lcd_write(LCD_WrData,*puts);
           puts++;
           col++;
     }
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
        delay_us(10);
        LCD_clk = 0;
    }
    LCD_cs = 0;
}

