#ifndef _RELAY_H
#define _RELAY_H

typedef enum JK_STATE
{
    JK_ON  = 0,
    JK_OFF = 1
} JK_State;

void jk_off_on(JK_State state);
