#ifndef _KEY_H
#define _KEY_H
#include "stc12c5a60s2.h"

sbit key_0 = P3^2;
sbit key_1 = P3^3;
sbit key_2 = P3^4;
sbit key_3 = P3^5;

typedef enum KEY_VALUE
{
    KEY0 = 0x01,
    KEY1 = 0x02,
    KEY2 = 0x03,
    KEY3 = 0x04,
    KEYNULL = 0xff
} KEY_Value;

KEY_Value key_scan(void);

#endif
