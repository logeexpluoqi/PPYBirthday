#include "init.h"
#include "stc12c5a60s2.h"
#include "delay.h"
#include "beep.h"
#include "relay.h"
#include "ds18b20.h"
#include "task.h"

void init_fcn()
{
	P0M0 = 0xff;
	P0M1 = 0x00;
	task_init();
	bee(BEEP_ON);
    delay_ms(200);
    bee(BEEP_OFF);
	jk_off_on(JK_OFF);
}
