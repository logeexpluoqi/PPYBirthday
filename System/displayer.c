/*
 * @Author: luoqi 
 * @Date: 2020-10-14 22:28:08 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-10-15 00:55:30
 */
#include "displayer.h"
#include "lcd12864.h"

Display displayer;

void displayer_init()
{
    unsigned char i, j;
    
    lcd_init();
	lcd_bk_off_on(LCD_ON);

    for(i = 0; i < 16; i++)
    {
        for(j = 0; j < 64; j++)
        {
            displayer.display_layer1[j][i] = 0x00;
            // displayer.display_layer2[j][i] = 0x00;
            // displayer.display_layer3[j][i] = 0x00;
        }
    }
}

void displayer_show(Display disp)
{
    lcd_set_dot(5, 5);
}

void displayer_clear()
{
    
}

void displayer_close()
{

}