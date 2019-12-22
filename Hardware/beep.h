#ifndef _BEEP_H
#define _BEEP_H

typedef enum BEEP_STATE
{
    BEEP_ON = 1,
    BEEP_OFF = 0
} BeepState;

void bee(BeepState state);

#endif
