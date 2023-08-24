/*
 * main.c
 *
 * Created: 8/18/2023 12:38:54 AM
 *  Author: Ahmed
 */  


#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/GIE/GIE_Prog.c"
#include "MCAL/ADC/ADC_Prog.c"
#include "MCAL/EXTI/EXTI_Prog.c"
#include "HAL/POTENTIOMETER/POTENTIOMETER_Prog.c"
#include "HAL/LM35/LM35_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"
#include "HAL/LCD/LCD_Prog.c"

#include <util/delay.h>

static u8 global_boolSensorFlag = 1;

void ISR_INT0(void);

void main(void)
{
	// enable global interrupts
	sei();
	
	// initialize LM35 temperature sensor
	LM35_voidInit(); // channel 0
	
	// initialize potentiometer
	POTENTIOMETER_voidInit(); // channel 1
	
	// initialize LCD
	LCD_voidInitDisplay();
	
	// initialize external interrupt
	EXTI_voidInit();
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT0);
	EXTI_voidEnableInterrupt(EXTI_GICR_INT0);
	EXTI_voidSetCallBack(ISR_INT0, EXTI_INT0);
	
	u16 local_u16ADCChannelReading = 0;
	
	while(true)
	{	
		if (global_boolSensorFlag == true)
		{
			local_u16ADCChannelReading = POTENTIOMETER_u16GetReadingInMilliVolt();
			LCD_voidDisplayInt(local_u16ADCChannelReading);
			LCD_voidDisplayStr(" mV");
		}
		else if (global_boolSensorFlag == false)
		{
			local_u16ADCChannelReading = LM35_u16GetReadingInCelcius();
			LCD_voidDisplayInt(local_u16ADCChannelReading);
			LCD_voidDisplayStr(" C");
		}
		_delay_ms(1000);
		LCD_voidClrDisplay();
	}
}

void ISR_INT0(void)
{
	global_boolSensorFlag ^= 1;
}
