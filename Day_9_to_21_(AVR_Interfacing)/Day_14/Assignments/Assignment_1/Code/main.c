/*
 * main.c
 *
 * Created: 8/21/2023 9:52:25 PM
 *  Author: Ahmed
 */ 
#define F_CPU 8000000
#define TRUE 1
#define FALSE 0

#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/EXTI/EXTI_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"
#include "HAL/LED/LED_Prog.c"

void ISR_INT0(void); 
u8 global_u8PatternSwitchFlag = 0;

static void pattern0(void);
static void pattern1(void);

void main(void)
{
	// LED array initialization
    LED_voidLEDArrayInit(DIO_PORTA);
	// switch initialization
	BTN_voidButtonInit(DIO_PORTD, DIO_PIN2);
	// interrupt initialization
	sei();
	EXTI_voidEnableInterrupt(EXTI_GICR_INT0);
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_ANY_CHANGE, EXTI_GICR_INT0);
	EXTI_voidSetCallBack(ISR_INT0, EXTI_INT0);
	while(TRUE)
    {
		if (global_u8PatternSwitchFlag == 0)
			pattern0();
		else
			pattern1();
    }
}

void ISR_INT0(void)
{
	global_u8PatternSwitchFlag ^= 1;
}
static void pattern0(void)
{
	LED_voidToggleLEDArray(DIO_PORTA);
	_delay_ms(500);
}
static void pattern1(void)
{
	LED_voidToggleLEDArray(DIO_PORTA);
	_delay_ms(2000);
}