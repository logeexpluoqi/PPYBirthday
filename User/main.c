/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:38:41 
 * @Last Modified by: luoqi
 * @Last Modified time: 2019-12-24 22:41:36
 */
#include "stc12c5a60s2.h"
#include "task.h"
#include "beep.h"
#include "relay.h"
#include "delay.h"
#include "key.h"

extern KEY_Value keyVal;

void main()
{
	P0 = 0x81;
	P2 = 0xff;
	init_fcn();

    while(1)
    {  
        task_process();
        if(keyVal != KEYNULL)
            bee(BEEP_ON);
        else
            bee(BEEP_OFF);   
    }
}
