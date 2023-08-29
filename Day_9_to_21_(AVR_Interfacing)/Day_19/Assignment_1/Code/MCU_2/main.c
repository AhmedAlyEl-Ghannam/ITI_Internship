/*
 * main.c
 *
 * Created: 8/16/2023 12:51:24 PM
 *  Author: Ahmed
 */ 

#include "LIB/Bit_Math.h"
#include "LIB/STD_Types.h"
#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/USART/USART_Prog.c"
#include "HAL/LCD/LCD_Prog.c"
#include <util/delay.h>


void main(void)
{
	
	USART_voidInit();
	
	LCD_voidInitDisplay();
	
	u8 local_u8Data = 0;
	
    while(true)
    {
		local_u8Data = USART_u8ReceiveData();
		LCD_voidDisplayChar(local_u8Data);
		_delay_us(10);
    }
}