/*
 * main.c
 *
 * Created: 8/20/2023 6:38:55 PM
 *  Author: Ahmed
 */ 
//#define NULL ((*void)0)
#define F_CPU 8000000
#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"
#include "HAL/STP_MOTOR/STPM_Prog.c"
#include "HAL/LCD/LCD_Prog.c"
#define TRUE 1
#define FALSE 0


int main(void)
{
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN0);
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN1);
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN2);
	
	LCD_voidInitDisplay();
	
	STPM_voidInitMotor();
	
	u8 local_u8ButtonReading;
	
    while(TRUE)
    {
         local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);
		 if (local_u8ButtonReading == BTN_PRESSED)
		 {
			_delay_ms(1);
			local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);
			if (BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0) == BTN_PRESSED)
			{
				while (local_u8ButtonReading == BTN_PRESSED)
					local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);
				LCD_voidSetCursorPosition(0, 1);
				LCD_voidDisplayStr("Clockwise");
				local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN2);
				while (local_u8ButtonReading == BTN_RELEASED)
				{
					STPM_voidRotateCW();
					local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN2);
				}
				LCD_voidClrDisplay();
			}
		 }
		 
		 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN1);
		 if (local_u8ButtonReading == BTN_PRESSED)
		 {
			 _delay_ms(1);
			 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN1);
			 if (BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN1) == BTN_PRESSED)
			 {
				 while (local_u8ButtonReading == BTN_PRESSED)
				 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN1);
				 LCD_voidSetCursorPosition(0, 1);
				 LCD_voidDisplayStr("Anticlockwise");
				 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN2);
				 while (local_u8ButtonReading == BTN_RELEASED)
				 {
					 STPM_voidRotateACW();
					 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN2);
				 }
				 LCD_voidClrDisplay();
			 }
		 }
    }
}