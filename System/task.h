/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:41:17 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-10-14 23:51:12
 */
#ifndef _TASK_H
#define _TASK_H

#define NULL (void*)0
	
#define TASK_NUM  9
	
typedef struct TASK_COMPONENTS
{
	unsigned char TaskIsRunFlag;
	unsigned int  TaskTimer;
	unsigned int  TaskIntervalTime;
	void (*TaskHook)(void* param);
} TaskInitTypeDef;

void task_init(void);
void task_process(void);
void task_rhythm(void);

void task_display(void);

void task_1ms(void);
void task_5ms(void);
void task_10ms(void);
void task_20ms(void);
void task_50ms(void);
void task_100ms(void);
void task_200ms(void);
void task_500ms(void);
void task_1s(void);
void task_5s(void);
void task_10s(void);



#endif
