/*
 * main.c
 *
 * Created: 8/16/2023 12:51:24 PM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"

#define TRUE 1

void main(void)
{
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
    while(TRUE)
    {
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_LOW);
		_delay_ms(1000);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_HIGH);
		_delay_ms(1000);	
    }
}