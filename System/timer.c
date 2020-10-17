/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:41:22 
 * @Last Modified by:   luoqi 
 * @Last Modified time: 2019-12-24 22:41:22 
 */
#include "timer.h"
#include "stc12c5a60s2.h"
#include "task.h"
#include "beep.h"
#include "relay.h"

extern unsigned int delay_ms_cnt;

void timer0_init()
{
    AUXR |= 0x80;		//定时器时钟1T模式
	TMOD =  0x01;		//设置定时器模式
	TL0  =  0x20;		//设置定时初值
	TH0  =  0xd1;		//设置定时初值
	TR0  =  1;		    //定时器0开始计时
    ET0  =  1;
    EA   =  1;
}

void timer0_int() interrupt 1 
{
    TL0 = 0x20;
    TH0 = 0xd1;
    delay_ms_cnt --;
    if(delay_ms_cnt == 0)
    {
        delay_ms_cnt = 0;
    }
    task_rhythm();
}
