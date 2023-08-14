/*
 * lab_4.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#define TRUE 1

// PORTC = C7 C6 C5 C4 C3 C2 C1 C0
//		   0   G  F  E  D  C  B  A

typedef enum sevenSegment
{
	SS_ZERO = 0x3F,
	SS_ONE = 0x06,
	SS_TWO = 0x5B,
	SS_THREE = 0x4F,
	SS_FOUR = 0x66,
	SS_FIVE = 0x6D,
	SS_SIX = 0x7D,
	SS_SEVEN = 0x07,
	SS_EIGHT = 0x7F,
	SS_NINE = 0x6F
} sevenSegment;

typedef unsigned char u8;

u8 SS_values[] = {SS_ZERO,
				  SS_ONE,
				  SS_TWO,
				  SS_THREE,
				  SS_FOUR,
				  SS_FIVE,
				  SS_SIX,
				  SS_SEVEN,
				  SS_EIGHT,
				  SS_NINE
				 };

void main(void)
{
	DDRC = 0xFF;
	u8 i;
	while (TRUE)
	{
		for (i = 0; i < 10; i++)
		{
			PORTC = SS_values[i];
			_delay_ms(1000);
		}
	}

}
