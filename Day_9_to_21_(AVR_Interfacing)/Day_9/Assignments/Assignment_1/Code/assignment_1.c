/*
 * assignment_1.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Ahmed
 */


#include <avr/io.h>
#include <util/delay.h>
#include "Bit_Math.h"
#include "STD_Types.h"
#define TRUE 1

typedef enum led_pattern
{
	P_ZERO = 0x00,
	P_ONE = 0x01,
	P_TWO = 0x03,
	P_THREE = 0x07,
	P_FOUR = 0x0F,
	P_FIVE = 0x1F,
	P_SIX = 0x3F,
	P_SEVEN = 0x7F,
	P_EIGHT = 0xFF
} led_pattern;

u8 pattern_1[] = {P_ONE, P_TWO, P_THREE, P_FOUR, P_FIVE, P_SIX, P_SEVEN, P_EIGHT, P_ZERO};

void pattern1(void);
void pattern1_reversed(void);

void main(void)
{
	DDRA = 0xFF;
	while (TRUE)
	{
		SET_PORT_TO_VAL(PORTA, pattern_1[8]);
		_delay_ms(250);

		pattern1();

		//_delay_ms(500);

		//pattern1_reversed(); (The program stops once the loop ends and I don't know why)
		SET_PORT_TO_VAL(PORTA, pattern_1[6]);
		_delay_ms(250);
		SET_PORT_TO_VAL(PORTA, pattern_1[5]);
		_delay_ms(250);
		SET_PORT_TO_VAL(PORTA, pattern_1[4]);
		_delay_ms(250);
		SET_PORT_TO_VAL(PORTA, pattern_1[3]);
		_delay_ms(250);
		SET_PORT_TO_VAL(PORTA, pattern_1[2]);
		_delay_ms(250);
		SET_PORT_TO_VAL(PORTA, pattern_1[1]);
		_delay_ms(250);
		SET_PORT_TO_VAL(PORTA, pattern_1[0]);
		_delay_ms(250);

	}

}

void pattern1(void)
{
	u8 i;
	for (i = 0; i < 8; i++)
	{
		SET_PORT_TO_VAL(PORTA, pattern_1[i]);
		_delay_ms(250);
	}
}

void pattern1_reversed(void)
{
	u8 i;
	for (i = 6; i >= 0; i--)
	{
		SET_PORT_TO_VAL(PORTA, pattern_1[i]);
		_delay_ms(250);
	}
}




