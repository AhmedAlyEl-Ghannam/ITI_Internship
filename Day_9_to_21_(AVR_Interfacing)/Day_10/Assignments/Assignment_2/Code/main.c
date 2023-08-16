/*
 * main.c
 *
 * Created: 8/16/2023 2:21:22 AM
 *  Author: Ahmed
 */ 

#include "LIB/STD_Types.h"
#include "MCAL/DIO/DIO_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/SEVEN_SEGMENT/SS_Prog.c"
#define F_CPU 8000000
#include <util/delay.h>

#define TRUE 1

void LED_pattern0(void);
void LED_pattern1(void);
void LED_pattern2(void);
void LED_pattern3(void);
void LED_pattern4(void);
void LED_pattern5(void);
void LED_pattern6(void);
void LED_pattern7(void);

int main(void)
{
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT);
	DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN2, DIO_PIN_INPUT);
	
	LED_voidLEDArrayInit(DIO_PORTB);
	
	u8 switch_combination;
	while(TRUE)
    {
		switch_combination = (DIO_u8GetPinValue(DIO_PORTA, DIO_PIN0) << 0)
						   + (DIO_u8GetPinValue(DIO_PORTA, DIO_PIN1) << 1) 
						   + (DIO_u8GetPinValue(DIO_PORTA, DIO_PIN2) << 2);
		switch (switch_combination)
		{
			case 0: LED_pattern0(); break; // flash every 500ms
			case 1: LED_pattern1(); break; // shift left every 250ms
			case 2: LED_pattern2(); break; // shift right every 250ms
			case 3: LED_pattern3(); break; // 2 LEDs converging every 300ms
			case 4: LED_pattern4(); break; // 2 LEDs diverging every 300ms
			case 5: LED_pattern5(); break; // ping-pong effect every 250ms
			case 6: LED_pattern6(); break; // incrementing (snake effect) every 300ms
			case 7: LED_pattern7(); break; // 2 LEDs converging/diverging every 300ms
		}
    }
}

void LED_pattern0(void) // flash every 500ms
{
	LED_voidToggleLEDArray(DIO_PORTB);
	_delay_ms(500);
}
void LED_pattern1(void) // shift left every 250ms
{
	u8 i;
	for (i = DIO_PIN0; i <= DIO_PIN7; i++)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		_delay_ms(250);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_LOW);
	}
	LED_voidTurnArrayLEDOnOff(DIO_PORTB, DIO_PORT_LOW);
}

void LED_pattern2(void) // shift right every 250ms
{
	u8 i;
	for (i = DIO_PIN7; i >= DIO_PIN0; i--)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		_delay_ms(250);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_LOW);
		if (i == DIO_PIN0)
			break;
	}
	LED_voidTurnArrayLEDOnOff(DIO_PORTB, DIO_PORT_LOW);
}

void LED_pattern3(void) // 2 LEDs converging every 300ms
{
	u8 i;
	for (i = DIO_PIN0; i < DIO_PIN4; i++)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN7 - i, DIO_PIN_HIGH);
		_delay_ms(300);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_LOW);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN7 - i, DIO_PIN_LOW);
	}
}

void LED_pattern4(void) // 2 LEDs diverging every 300ms
{
	u8 i;
	for (i = DIO_PIN3; i >= DIO_PIN0; i--)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN7 - i, DIO_PIN_HIGH);
		_delay_ms(300);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_LOW);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN7 - i, DIO_PIN_LOW);
		if (i == DIO_PIN0)
			break;
	}
}

void LED_pattern5(void) // ping-pong effect every 250ms
{
	u8 i;
	for (i = DIO_PIN0; i <= DIO_PIN7; i++)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		_delay_ms(250);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_LOW);
	}
	
	for (i = DIO_PIN6; i >= DIO_PIN0; i--)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		_delay_ms(250);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_LOW);
		if (i == DIO_PIN0)
			break;
	}
}

void LED_pattern6(void) // incrementing (snake effect) every 300ms
{
	u8 i;
	for (i = DIO_PIN0; i <= DIO_PIN7; i++)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, i, DIO_PIN_HIGH);
		_delay_ms(250);
	}
	LED_voidTurnArrayLEDOnOff(DIO_PORTB, DIO_PORT_LOW);
}

void LED_pattern7(void) // 2 LEDs converging/diverging every 300ms
{
	LED_pattern3();
	LED_pattern4();
}