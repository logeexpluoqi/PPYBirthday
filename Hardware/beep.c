#include "beep.h"
#include "stc12c5a60s2.h"

sbit beep = P0^0;
void bee(BeepState state)
{
    if(state)
        beep = 0;
    else
        beep = 1;  
}


