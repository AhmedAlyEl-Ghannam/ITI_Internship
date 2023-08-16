/*
 * main.c
 *
 * Created: 8/16/2023 1:09:42 AM
 *  Author: Ahmed
 */ 

#include "LIB/STD_Types.h"
#include "MCAL/DIO/DIO_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/SEVEN_SEGMENT/SS_Prog.c"
#define F_CPU 8000000
#include <util/delay.h>

#define TRUE 1

void green_LED(void);
void yellow_LED(void);
void red_LED(void);


int main(void)
{
    LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN0);
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN1);
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN2);
	
	SS_voidSevenSegInit(DIO_PORTB);
	
	while(TRUE)
    {
        green_LED();
		yellow_LED();
		red_LED();
    }
}

void green_LED(void)
{
	LED_voidToggleLEDSingle(DIO_PORTA, DIO_PIN0);
	u8 i;
	for (i = 9; i >= 0; i--)
	{
		SS_voidDisplayNumber(DIO_PORTB, SS_values[i]);
		_delay_ms(1000);
		if (i == 0)
			break;
	}
	LED_voidToggleLEDSingle(DIO_PORTA, DIO_PIN0);
}

void yellow_LED(void)
{
	LED_voidToggleLEDSingle(DIO_PORTA, DIO_PIN1);
	u8 i;
	for (i = 3; i >= 0; i--)
	{
		SS_voidDisplayNumber(DIO_PORTB, SS_values[i]);
		_delay_ms(1000);
		if (i == 0)
			break;
	}
	LED_voidToggleLEDSingle(DIO_PORTA, DIO_PIN1);
}

void red_LED(void)
{
	LED_voidToggleLEDSingle(DIO_PORTA, DIO_PIN2);
	u8 i;
	for (i = 9; i >= 0; i--)
	{
		SS_voidDisplayNumber(DIO_PORTB, SS_values[i]);
		_delay_ms(1000);
		if (i == 0)
			break;
	}
	LED_voidToggleLEDSingle(DIO_PORTA, DIO_PIN2);
}
