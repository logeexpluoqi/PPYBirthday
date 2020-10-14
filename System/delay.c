/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:41:03 
 * @Last Modified by:   luoqi 
 * @Last Modified time: 2019-12-24 22:41:03 
 */
#include "delay.h"
#include "timer.h"

#include<intrins.h>

unsigned int delay_ms_cnt;

void delay_us(unsigned int us)
{
	unsigned int i;
	
	for(i=0; i<us; i++)
	{
		_nop_();	_nop_();
		_nop_();	_nop_();
		_nop_();	_nop_();
		_nop_();	_nop_();
		_nop_();	_nop_();
		_nop_();	_nop_();
	}
}

void delay_ms(unsigned int ms)
{
	delay_ms_cnt = ms;
	while(delay_ms_cnt);
}

