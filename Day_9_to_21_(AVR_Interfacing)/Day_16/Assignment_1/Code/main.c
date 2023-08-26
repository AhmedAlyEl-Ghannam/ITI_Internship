/*
 * main.c
 *
 * Created: 8/20/2023 6:38:55 PM
 *  Author: Ahmed
 */ 
#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/GIE/GIE_Prog.c"
#include "MCAL/TIMER/TIMER_Prog.c"
#include "MCAL/ADC/ADC_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"
#include "HAL/LCD/LCD_Prog.c"
#include "HAL/BUZZER/BUZZER_Prog.c"
#include <util/delay.h>

static volatile u32 timer_counter = 0;
u32 timer_counter_max = 1000;
volatile u8 timer_store_in_OCR = 0;
u16 hehe = 0;
void timer0_ISR(void);

void main(void)
{
	sei();
	
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN0);
	
	ADC_voidInit();
	
	LCD_voidInitDisplay();
	
	BUZZER_voidInit();
	
	TMR0_voidInit();
	TMR_voidCallBack(timer0_ISR, TMR0_CTC_VECTOR_ID);
	TMR0_voidSetOVF(125);
	
		
	while(true)
    {
		hehe = ADC_u8GetResultSync(ADC_CHANNEL_0);
		LCD_voidDisplayInt(hehe);
		//BUZZER_voidToggleBuzzerOnOff();
		_delay_ms(500);
		LCD_voidClrDisplay();
		//BUZZER_voidToggleBuzzerOnOff();
    }
}

void timer0_ISR(void)
{
	timer_counter++;
	if (timer_counter == timer_counter_max)
	{
		BUZZER_voidToggleBuzzerOnOff();
		timer_store_in_OCR = (hehe / 4) - 1;
		timer_counter = 0;
		TMR0_voidSetCTC(timer_store_in_OCR);
	}	
}



