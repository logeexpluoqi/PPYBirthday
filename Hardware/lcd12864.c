/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:24 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-03-14 22:47:34
 */
#include "lcd12864.h"
#include "delay.h"

void lcd_init()
{

    lcd_write_data(LCD_WRITE_CMD, 0x02);
    lcd_write_data(LCD_WRITE_CMD, 0x06);
    lcd_write_data(LCD_WRITE_CMD, 0x36);
}

void lcd_clear()
{
    lcd_write_data(LCD_WRITE_CMD, 0x30);
    lcd_write_data(LCD_WRITE_CMD, 0x01);
}

void lcd_write_byte(unsigned char w_data)
{
    unsigned char i;

    lcd_clk = 0;
    for (i = 0; i < 8; i++)
    {
        lcd_sda_out = ((w_data & 0x80) == 0x80);
        lcd_clk = 1;
        w_data = w_data << 1;
        lcd_clk = 0;
    }
}

unsigned char lcd_read_byte()
{
    unsigned char i;
    unsigned char high_four_bit = 0;
    unsigned char low_four_bit = 0;

    for (i = 0; i < 16; i++)
    {
        lcd_clk = 0;
        lcd_clk = 1;
        if (i < 8)
        {
            high_four_bit = (lcd_sda_in == 1);
            high_four_bit = high_four_bit << 1;
        }
        else
        {
            low_four_bit = (lcd_sda_in == 1);
            low_four_bit = low_four_bit << 1;
        }
        lcd_clk = 0;
    }
    return (high_four_bit | low_four_bit);
}

void lcd_check_busy()
{
    lcd_cs = 1;
    do
    {
        lcd_write_byte(LCD_READ_STATE);
    } while (lcd_read_byte() == 0x80);
    lcd_cs = 0;
}

void lcd_bk_off_on(LcdBk state)
{
    if (state == LCD_ON)
    {
        lcd_bk = 0;
    }
    else
    {
        lcd_bk = 1;
    }
}

unsigned char lcd_read_data()
{
    unsigned char rdata;
    lcd_check_busy();
    lcd_cs = 1;
    lcd_write_byte(LCD_READ_DATA);
    rdata = lcd_read_byte();
    lcd_cs = 0;
    return rdata;
}

void lcd_write_data(unsigned char cmd, unsigned char w_data)
{
    unsigned char i;
    unsigned char high_four_bit = (w_data & 0xf0);
    unsigned char low_four_bit = ((w_data << 4) & 0xf0);

    lcd_check_busy();
    lcd_cs = 1;
    for (i = 0; i < 24; i++)
    {
        lcd_clk = 0;
        if (i < 8)
        {
            lcd_sda_out = ((cmd & 0x80) == 0x80);
            cmd = cmd << 1;
        }
        else if (i >= 8 && i < 15)
        {
            lcd_sda_out = ((high_four_bit & 0x80) == 0x80);
            high_four_bit = high_four_bit << 1;
        }
        else
        {
            lcd_sda_out = ((low_four_bit & 0x80) == 0x80);
            low_four_bit = low_four_bit << 1;
        }
        lcd_clk = 1;
    }
    lcd_cs = 0;
    lcd_sda_out = 0;
    lcd_clk = 0;
}

void lcd_set_dot(unsigned char x, unsigned char y)
{
    unsigned char x_addr = x >> 4;

    x = x % 16;
    lcd_write_data(LCD_WRITE_CMD, 0x36);
    lcd_write_data(LCD_WRITE_CMD, 0x80 | y);
    lcd_write_data(LCD_WRITE_CMD, 0x80 | x_addr);
    if (x < 8)
    {
        lcd_write_data(LCD_WRITE_DATA, (0x01 >> x));
        lcd_write_data(LCD_WRITE_DATA, 0x00);
    }
    else
    {
        lcd_write_data(LCD_WRITE_DATA, 0x00);
        lcd_write_data(LCD_WRITE_DATA, (0x01 >> (x + 7)));
    }
}

void lcd_set_graph(unsigned char graph[16][64])
{
    unsigned char i, j;

    lcd_write_data(LCD_WRITE_CMD, 0x36);
    for (j = 0; j < 64; j++)
    {
        lcd_write_data(LCD_WRITE_CMD, (0x80 | j));
        for (i = 0; i < 16; i++)
        {
            lcd_write_data(LCD_WRITE_CMD, (0x80 | (i >> 2)));
            lcd_write_data(LCD_WRITE_DATA, graph[i][j]);
            lcd_write_data(LCD_WRITE_DATA, graph[i + 1][j]);
        }
    }
}

