/*
 * main.c
 *
 * Created: 8/18/2023 12:38:54 AM
 *  Author: Ahmed
 */  


#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/GIE/GIE_Prog.c"
#include "HAL/LDR/LDR_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/LCD/LCD_Prog.c"

#include <util/delay.h>



void main(void)
{
	// enable global interrupts
	sei();
	
	// initialize LED
	LED_voidLEDSingleInit(DIO_PORTB, DIO_PIN6); 
	
	// initialize LDR
	LDR_voidInit();
	
	// initialize LCD
	LCD_voidInitDisplay();
	
	u16 local_u16LDRReading = 0;
	
	while(true)
	{	
		local_u16LDRReading = LDR_u16GetReadingInMilliVolt();
		LCD_voidDisplayInt(local_u16LDRReading);
		if (local_u16LDRReading < 2500) // high light intensity
			LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
		else // low light intensity
			LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);

		_delay_ms(1000);
		LCD_voidClrDisplay();
	}
}
