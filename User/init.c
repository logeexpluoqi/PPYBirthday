/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:38 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-01-08 01:01:16
 */
#include "init.h"
#include "beep.h"
#include "delay.h"
#include "ds18b20.h"
#include "lcd12864.h"
#include "relay.h"
#include "stc12c5a60s2.h"
#include "task.h"

void init_fcn()
{
	P0M0 = 0xff;
	P0M1 = 0x00;
	task_init();
	lcd_init();
	lcd_set_dot(5, 5);
	lcd_bk_off_on(LCD_ON);
	bee(BEEP_ON);
	delay_ms(200);
	bee(BEEP_OFF);
	jk_off_on(JK_OFF);
}
