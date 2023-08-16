/*
 * lab1.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Ahmed
 */

#include <avr/io.h>
#include <util/delay.h>

#include "Bit_Math.h"
#include "STD_Types.h"

#define TRUE 1

void main(void)
{
	CLR_BIT(DDRA, PA0);
	//SET_PORT(PORTA);
	SET_PORT(DDRB);
	while (TRUE)
	{
		if (GET_BIT(PINA, PA0))
		{
			_delay_ms(30);
			if (GET_BIT(PINA, PA0))
			{
				SET_PORT(PORTB);
				_delay_ms(470);
				CLR_PORT(PORTB);
				_delay_ms(500);
			}
		}
	}
}
