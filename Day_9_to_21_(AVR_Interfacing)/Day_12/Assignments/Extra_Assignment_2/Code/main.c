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
#include "HAL/BUTTON/BUTTON_Prog.c"
#include "HAL/LCD/LCD_Prog.c"

#define TRUE 1


void main(void)
{
	// buttons initialization
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN0);
	//BTN_voidButtonInit(DIO_PORTC, DIO_PIN1);
	
	// LCD initialization
	LCD_voidInitDisplay();
	
	u8 haha;
	u8 hehe[] = {'P', 'R', 'E', 'S', 'S', ' ' , 'F', '\0'};
	
    while(TRUE)
    {
		haha = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);
		if (haha == BTN_PRESSED)
		{
			_delay_ms(25);
			haha = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);
			if (haha == BTN_PRESSED)
			{
				while (haha == BTN_PRESSED)
					haha = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);
				LCD_voidDisplayStr(hehe);
			}
		}
    }
}
