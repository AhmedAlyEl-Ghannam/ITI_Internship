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
#include "HAL/LCD/LCD_Prog.c"

#define TRUE 1


void main(void)
{
	
	// LCD initialization
	LCD_voidInitDisplay();
	
	u8 local_u8IteratorCol;
	u8 local_u8IteratorRow = 1;
    while(TRUE)
    {
		for (local_u8IteratorCol = 0; local_u8IteratorCol < 16; local_u8IteratorCol++)
		{
			LCD_voidSetCursorPosition(local_u8IteratorCol, local_u8IteratorRow+1);
			_delay_ms(1);
			LCD_voidDisplayChar('H');
			LCD_voidDisplayChar('I');
			_delay_ms(500);
			LCD_voidClrDisplay();
			TOG_BIT(local_u8IteratorRow, 0);
		}
    }
}
