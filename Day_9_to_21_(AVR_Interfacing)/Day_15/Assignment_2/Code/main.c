/*
 * main.c
 *
 * Created: 8/18/2023 12:38:54 AM
 *  Author: Ahmed
 */  


#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/GIE/GIE_Prog.c"
#include "HAL/LM35/LM35_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/LCD/LCD_Prog.c"

#include <util/delay.h>



void main(void)
{
	// enable global interrupts
	sei();
	
	// initialize LEDs
	LED_voidLEDSingleInit(DIO_PORTB, DIO_PIN5); //green
	LED_voidLEDSingleInit(DIO_PORTB, DIO_PIN6); // yellow
	LED_voidLEDSingleInit(DIO_PORTB, DIO_PIN7); // red
	
	// initialize ADC
	LM35_voidInit();
	
	// initialize LCD
	LCD_voidInitDisplay();
	
	u16 local_u16LM35Reading = 0;
	
	while(true)
	{	
		local_u16LM35Reading = LM35_u16GetReadingInCelcius();
		LCD_voidDisplayInt(local_u16LM35Reading);
		if (local_u16LM35Reading < 20)
			LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN5, DIO_PIN_HIGH);
		else if (local_u16LM35Reading < 40)
			LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
		else // more than or equal 40
			LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN7, DIO_PIN_HIGH);
		_delay_ms(1000);
		LCD_voidClrDisplay();
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN5, DIO_PIN_LOW);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
		LED_voidTurnSingleLEDOnOff(DIO_PORTB, DIO_PIN7, DIO_PIN_LOW);
	}
}
