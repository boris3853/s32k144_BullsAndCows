/*
 * _4ND_7seg.h
 *
 *  Created on: Feb 22, 2022
 *      Author: Kyung
 */

#ifndef _4ND_7SEG_H_
#define _4ND_7SEG_H_

#include "define.h"

void _4ND_7SEG_init(void);
void delay_us(int num);
void delay_ms(int num);
void d_clear(void);
void d_output(int digit, int num);
void SEG3NUM(int num);

#endif /* _4ND_7SEG_H_ */


