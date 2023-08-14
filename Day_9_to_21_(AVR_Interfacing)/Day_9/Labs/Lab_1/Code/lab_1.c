/*
 * lab_1.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#define TRUE 1

void main(void)
{
	SET_BIT(DDRA, PA0);
	SET_BIT(PORTA, PA0);
	while (TRUE);
}
