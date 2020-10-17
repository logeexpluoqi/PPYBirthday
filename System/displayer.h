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
    unsigned char IsRefresh;
    /* this screan is 128x64 pixls, a total of 1024 byte */
    unsigned char DisplayLayer1[1024];
    // unsigned char display_layer2[1024];
    // unsigned char display_layer3[1024];
} Display;

void displayer_init(void);
void displayer_show(void);
void displayer_close(void);
void displayer_clear(void);


#endif
