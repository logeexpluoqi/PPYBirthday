/*
 * @Author: luoqi 
 * @Date: 2019-12-24 22:40:53 
 * @Last Modified by:   luoqi 
 * @Last Modified time: 2019-12-24 22:40:53 
 */
#ifndef _BEEP_H
#define _BEEP_H

typedef enum BEEP_STATE
{
    BEEP_ON = 1,
    BEEP_OFF = 0
} BeepState;

void bee(BeepState state);

#endif
