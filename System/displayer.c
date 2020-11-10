/*
 * @Author: luoqi 
 * @Date: 2020-10-14 22:28:08 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-11-10 11:15:38
 */
#include "displayer.h"
#include "lcd12864.h"
#include "fonts.h"

Display displayer;

void displayer_init()
{
    unsigned int i; 
    
    lcd_init();
    displayer_clear();
	lcd_bk_off_on(LCD_ON);

    displayer.IsRefresh = 0;
    for(i = 0; i < 10; i++)
    {
        displayer.DisplayLayer1[i] = 0;
    }
}

void displayer_show()
{
    if(displayer.IsRefresh)
    {
        


        displayer.IsRefresh = 0;
    }
}

void displayer_clear()
{
    
}

void displayer_close()
{
    
}