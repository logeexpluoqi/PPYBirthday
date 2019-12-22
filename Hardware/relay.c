#include "relay.h"
#include "stc12c5a60s2.h"

sbit JK = P0^6;

void jk_off_on(JK_State state)
{
    JK = state;
}

