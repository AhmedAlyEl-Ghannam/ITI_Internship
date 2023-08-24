/*
 * main.c
 *
 * Created: 8/18/2023 12:38:54 AM
 *  Author: Ahmed
 */  


#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/GIE/GIE_Prog.c"
#include "MCAL/ADC/ADC_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/LCD/LCD_Prog.c"

#include <util/delay.h>



void main(void)
{
	// enable global interrupts
	sei();
	
	// initialize LEDs
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN4);
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN5);
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN6);
	
	// initialize ADC
	ADC_voidInit();
	
	// initialize LCD
	LCD_voidInitDisplay();
	
	u16 local_u16ADCAnalogReading = 5000;
	
	u16 *local_u16ADCResult = NULL;
	
	while(true)
	{	
		local_u16ADCAnalogReading = (u16)(((u32)(ADC_u8GetResultSync(ADC_CHANNEL_0)) * VREF) / 1024UL);
		LCD_voidDisplayInt(local_u16ADCAnalogReading);
		_delay_ms(1000);
		LCD_voidClrDisplay();
	}
}
