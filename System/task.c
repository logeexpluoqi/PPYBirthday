/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:30 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-10-15 01:20:07
 */
#include "task.h"
#include "stc12c5a60s2.h"
#include "key.h"
#include "ds18b20.h"
#include "beep.h"
#include "relay.h"
#include "timer.h"
#include "displayer.h"

KEY_Value keyVal;

TaskInitTypeDef Tasks[TASK_NUM] = 
{
	{0, 10,	  10,	task_10ms},
	{0, 20,	  20,	task_20ms},
	{0, 35,	  35,	task_display},
	{0, 50,	  50,	task_50ms},
	{0, 100,  100,	task_100ms},
	{0, 200,  200,	task_200ms},
	{0, 500,  500,	task_500ms},
	{0, 1000, 1000, task_1s},
	{0, 5000, 5000, task_5s}
};

void task_init()
{
	timer0_init();
}

void task_rhythm()
{
	unsigned char i;
	
	for(i=0; i<TASK_NUM; i++)
	{
		if(Tasks[i].TaskTimer != 0)
		{
			Tasks[i].TaskTimer --;
			if(Tasks[i].TaskTimer == 0)
			{
				Tasks[i].TaskIsRunFlag = 1;
				Tasks[i].TaskTimer = Tasks[i].TaskIntervalTime;
			}
		}
	}
}

void task_process()
{
	unsigned char i;
	for(i=0; i<TASK_NUM; i++)
	{
		if(Tasks[i].TaskIsRunFlag == 1)
		{
			Tasks[i].TaskHook(NULL);
			Tasks[i].TaskIsRunFlag = 0;
		}
	}
}

void task_display()
{
	displayer_show();
}

void task_10ms()
{

}

void task_20ms()
{
	keyVal = key_scan();
}

void task_50ms()
{

}

void task_100ms()
{

}

void task_200ms()
{

}

void task_500ms()
{
	
}

void task_1s()
{
	
}

void task_5s()
{
	static unsigned char state = 0;

	state = ~state;
	if(state)
	{
		jk_off_on(JK_ON);
	}
	else
	{
		jk_off_on(JK_OFF); 
	}
}

void task_10s()
{

}

