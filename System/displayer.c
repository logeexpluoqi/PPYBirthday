/*
 * @Author: luoqi 
 * @Date: 2020-10-14 22:28:08 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-10-15 00:55:30
 */
#include "displayer.h"
#include "lcd12864.h"

Display displayer;

unsigned char disp_cache[1024] = {0};

void displayer_init()
{
    unsigned int i;
    
    lcd_init();
	lcd_bk_off_on(LCD_ON);

    displayer.IsRefresh = 0;
    for(i = 0; i < 1024; i++)
    {
        displayer.DisplayLayer1[i] = 0;
    }
}

void displayer_show()
{
    lcd_set_dot(5, 5);
    if(displayer.IsRefresh)
    {
        *disp_cache = *displayer.DisplayLayer1;
        displayer.IsRefresh = 0;
    }
}

void displayer_clear()
{
    
}

void displayer_close()
{

}