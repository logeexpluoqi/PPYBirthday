/*
 * @Author: luoqi 
 * @Date: 2020-10-14 22:28:03 
 * @Last Modified by: luoqi
 * @Last Modified time: 2020-10-15 00:46:50
 */

#ifndef _DISPLAYER_H
#define _DISPLAYER_H

typedef struct DISPLAYER
{
    unsigned char display_layer1[64][16];
    // unsigned char display_layer2[64][16];
    // unsigned char display_layer3[64][16];
} Display;

void displayer_init(void);
void displayer_show(Display disp);
void displayer_close(void);
void displayer_clear(void);


#endif
