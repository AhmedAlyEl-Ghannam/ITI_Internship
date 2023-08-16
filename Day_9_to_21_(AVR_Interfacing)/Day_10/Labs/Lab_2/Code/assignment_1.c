/*
 * assignment_1.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Ahmed
 */



#include <avr/io.h>
#include <util/delay.h>
#include "STD_Types.h"
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
	SET_PORT(DDRA);
	SET_BIT(DDRB, PB0);
	SET_BIT(DDRB, PB1);
	CLR_BIT(PORTB, PB0);
	SET_BIT(PORTB, PB1);
	u8 i;
	while (TRUE)
	{
		for (i = 0; i < 10; i++)
		{
			SET_PORT_TO_VAL(PORTA, SS_values[i]);
			_delay_ms(100);
			TOG_BIT(PORTB, PB0);
			TOG_BIT(PORTB, PB1);
		}
	}

}
