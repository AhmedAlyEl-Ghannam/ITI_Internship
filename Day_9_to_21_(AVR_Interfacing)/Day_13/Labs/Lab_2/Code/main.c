/*
 * main.c
 *
 * Created: 8/16/2023 12:51:24 PM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"

#define TRUE 1

void main(void)
{
	BTN_voidButtonInit(DIO_PORTA, DIO_PIN0);
	BTN_voidButtonInit(DIO_PORTA, DIO_PIN1);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN3, DIO_PIN_OUTPUT);
    while(TRUE)
    {
		while (BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN0) == 0)
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_PIN_HIGH);
		while (BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN1) == 0)
		{
			DIO_voidSetPinValue(DIO_PORTA, DIO_PIN3, DIO_PIN_HIGH);
			_delay_ms(500);
		}
			
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN2, DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTA, DIO_PIN3, DIO_PIN_LOW);
		
    }
}