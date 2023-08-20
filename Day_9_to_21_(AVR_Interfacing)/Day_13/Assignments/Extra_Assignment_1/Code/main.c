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

void steppermotor(void);
void dcmotor(void);

u8 global_u8IsPrintedSTP = 0;
u8 global_u8IsPrintedDC = 0;

void main(void)
{
	// stepper
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN0);
	// switch between motors
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN2);
	// DC 
	BTN_voidButtonInit(DIO_PORTC, DIO_PIN3);
	
	LCD_voidInitDisplay();
	
	STPM_voidInitMotor();
	
	// initialize DC
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	
	u8 local_u8SwitchingButtonReading;
	
	while(TRUE)
    {
         local_u8SwitchingButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN2);
		 
		 if (local_u8SwitchingButtonReading == BTN_PRESSED)
		 {
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
			DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, DIO_PIN_LOW);
			steppermotor();
		 }
		 else
		 {
			 STPM_voidStopMotor();
			 dcmotor();
		 }
    }
}

void steppermotor(void)
{
	u8 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN0);

	if (local_u8ButtonReading == BTN_PRESSED)
	{
		if (global_u8IsPrintedSTP != 1)
		{
			global_u8IsPrintedSTP = 1;
			LCD_voidClrDisplay();
			LCD_voidSetCursorPosition(0, 1);
			LCD_voidDisplayStr("Stepper Motor");
			LCD_voidSetCursorPosition(0, 2);
			LCD_voidDisplayStr("Clockwise");
		}
		STPM_voidRotateCW();
	}
	else
	{
		if (global_u8IsPrintedSTP != 0)
		{
			global_u8IsPrintedSTP = 0;
			LCD_voidClrDisplay();
			LCD_voidSetCursorPosition(0, 1);
			LCD_voidDisplayStr("Stepper Motor");
			LCD_voidSetCursorPosition(0, 2);
			LCD_voidDisplayStr("Anticlockwise");
		}
		STPM_voidRotateACW();
	}
}
void dcmotor(void)
{
	u8 local_u8ButtonReading = BTN_u8IsButtonPressed(DIO_PORTC, DIO_PIN3);

	if (local_u8ButtonReading == BTN_PRESSED)
	{
		if (global_u8IsPrintedDC != 1)
		{
			global_u8IsPrintedDC = 1;
			LCD_voidClrDisplay();
			LCD_voidSetCursorPosition(0, 1);
			LCD_voidDisplayStr("DC Motor");
			LCD_voidSetCursorPosition(0, 2);
			LCD_voidDisplayStr("Clockwise");
		}
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_HIGH);
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, DIO_PIN_LOW);
	}
	else
	{
		if (global_u8IsPrintedDC != 0)
		{
			global_u8IsPrintedDC = 0;
			LCD_voidClrDisplay();
			LCD_voidSetCursorPosition(0, 1);
			LCD_voidDisplayStr("DC Motor");
			LCD_voidSetCursorPosition(0, 2);
			LCD_voidDisplayStr("Anticlockwise");
		}
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN6, DIO_PIN_LOW);
		DIO_voidSetPinValue(DIO_PORTB, DIO_PIN7, DIO_PIN_HIGH);
	}
}