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

extern unsigned int delayMsCnt;

void timer0_init()
{
    AUXR |= 0x80;		//��ʱ��ʱ��1Tģʽ
	TMOD =  0x01;		//���ö�ʱ��ģʽ
	TL0  =  0x20;		//���ö�ʱ��ֵ
	TH0  =  0xd1;		//���ö�ʱ��ֵ
	TR0  =  1;		    //��ʱ��0��ʼ��ʱ
    ET0  =  1;
    EA   =  1;
}

void timer0_int() interrupt 1 
{
    TL0 = 0x20;
    TH0 = 0xd1;
    delayMsCnt --;
    if(delayMsCnt == 0)
    {
        delayMsCnt = 0;
    }
    task_rhythm();
}
