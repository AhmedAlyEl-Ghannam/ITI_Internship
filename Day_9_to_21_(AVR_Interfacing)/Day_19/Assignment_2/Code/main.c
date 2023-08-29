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
#include "HAL/LED/LED_Prog.c"
#include "HAL/DCM/DCM_Prog.c"
#include <util/delay.h>


void main(void)
{
	
	USART_voidInit();
	
	LED_voidLEDSingleInit(DIO_PORTC, DIO_PIN0);
		
	DCM_voidInit();
	
	u8 local_u8Data = 0;
	
    while(true)
    {
		local_u8Data = USART_u8ReceiveData();
		
		if (local_u8Data == '#')
		{
			DCM_voidStartMotorCW();
		}
		else if (local_u8Data == '$')
		{
			DCM_voidStopMotor();
		}
		else if (local_u8Data == '@')
		{
			LED_voidTurnSingleLEDOnOff(DIO_PORTC, DIO_PIN0, DIO_PIN_HIGH);
		}
			
		else if (local_u8Data == '&')
		{
			LED_voidTurnSingleLEDOnOff(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);
		}
    }
}