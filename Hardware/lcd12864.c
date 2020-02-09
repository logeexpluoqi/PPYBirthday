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
    lcd_rw(LCD_WrCmd, 0x30);
    lcd_rw(LCD_WrCmd, 0x0c);
    lcd_rw(LCD_WrCmd, 0x01);
    lcd_rw(LCD_WrCmd, 0x06);
}

void lcd_clear()
{
    unsigned char i;

    lcd_rw(LCD_WrCmd, 0x30);
    lcd_rw(LCD_WrCmd, 0x80);
    for(i=0; i<64; i++)
    {
        lcd_rw(LCD_WrData, 0x20);
    }
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
    lcd_rw(LCD_WrCmd, 0x30);     
    lcd_rw(LCD_WrCmd, AC_TABLE[8*row+col]);   
    while(*puts != '\0')      
    {
       if(col==8)           
       {            
           col='0';
           row++;
       }
       if(row==4) row='0';     
       lcd_rw(LCD_WrCmd, AC_TABLE[8*row+col]);
       lcd_rw(LCD_WrData, *puts);      
       puts++;
       lcd_rw(LCD_WrData, *puts);
       puts++;
       col++;
    }
}

unsigned char lcd_chek_busy()
{
    unsigned char i;
    unsigned char data_h_half;
    unsigned char data_l_half; 

    unsigned char cmd = LCD_RdState;

    LCD_clk = 0;
    LCD_cs  = 1;
    for(i=0; i<24; i++)
    {
        if(i<8)
        {
            LCD_sdi = ((cmd & 0x80) == 0x80);
            cmd = cmd << 1;
            LCD_clk = 1;
            delay_us(1);
            LCD_clk = 0;
        }
        if(i>=8 && i<16)
        {
            LCD_clk = 1;
            delay_us(1);
            LCD_clk = 0;
            data_h_half = LCD_sdi;
            data_h_half = data_h_half << 1;
        }
        else
        {
            LCD_clk = 1;
            delay_us(1);
            LCD_clk = 0;
            data_l_half = LCD_sdi;
            data_l_half = data_l_half << 1;
        }
    }
    LCD_cs = 0;

    if(((data_h_half & 0xf0) | (data_l_half & 0x0f)) & 0x20 == 0x20)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned char lcd_rw(LcdCmd cmd, unsigned char wdata)
{
    unsigned char i;
    unsigned char data_h_half;
    unsigned char data_l_half; 

    data_h_half = wdata & 0xf0;
    data_l_half = (wdata<<4) & 0xf0;

    if(lcd_chek_busy())
    {
        return 1;
    }
    else
    {
        LCD_clk = 0;
        LCD_cs  = 1;
        for(i=0; i<24; i++)
        {
            if(i<8)
            {
                LCD_sdi = ((cmd & 0x80) == 0x80);
                cmd = cmd << 1;
                LCD_clk = 1;
                delay_us(1);
                LCD_clk = 0;
            }
            if(i>=8 && i<16)
            {
                if(cmd != LCD_RdState || cmd != LCD_RdData)
                {
                    LCD_sdi = ((data_h_half & 0x80) == 0x80);
                }
                LCD_clk = 1;
                delay_us(1);
                LCD_clk = 0;

                data_h_half = LCD_sdi;
                data_h_half = data_h_half << 1;
            }
            else
            {
                if(cmd != LCD_RdState || cmd != LCD_RdData)
                {
                    LCD_sdi = ((data_l_half & 0x80) == 0x80); 
                }
                LCD_clk = 1;
                delay_us(1);
                LCD_clk = 0;
                data_l_half = LCD_sdi;
                data_l_half = data_l_half << 1;
            }
        }
        LCD_cs = 0;
        return ((data_h_half & 0xf0) | (data_l_half & 0x0f));
    }
}

