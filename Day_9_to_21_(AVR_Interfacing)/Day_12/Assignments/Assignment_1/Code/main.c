/*
 * main.c
 *
 * Created: 8/18/2023 12:38:54 AM
 *  Author: Ahmed
 */  
#define NULL ((void*)0)
#define F_CPU 8000000
#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"
#include "HAL/KEYPAD/Keypad_Prog.c"
#include "HAL/SEVEN_SEGMENT/SS_Prog.c"

#define TRUE 1


void main(void)
{
	SS_voidSevenSegInit(DIO_PORTA);
	KPD_voidInit(); // portc
	
    while(TRUE)
    {
		switch (KPD_u8GetPressedKey())
		{
			case '1': SS_voidDisplayNumber(DIO_PORTA, SS_ONE); break;
			case '2': SS_voidDisplayNumber(DIO_PORTA, SS_TWO); break;
			case '3': SS_voidDisplayNumber(DIO_PORTA, SS_THREE); break;
			case '4': SS_voidDisplayNumber(DIO_PORTA, SS_FOUR); break;
			case '5': SS_voidDisplayNumber(DIO_PORTA, SS_FIVE); break;
			case '6': SS_voidDisplayNumber(DIO_PORTA, SS_SIX); break;
			case '7': SS_voidDisplayNumber(DIO_PORTA, SS_SEVEN); break;
			case '8': SS_voidDisplayNumber(DIO_PORTA, SS_EIGHT); break;
			case '9': SS_voidDisplayNumber(DIO_PORTA, SS_NINE); break;
			case '0': SS_voidDisplayNumber(DIO_PORTA, SS_ZERO); break;
		}
    }
}
