/*
 * main.c
 *
 * Created: 8/17/2023 6:47:42 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"
#include "HAL/SEVEN_SEGMENT/SS_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"

#define TRUE 1
#define MAX_CAR_COUNT 25

s8 carCount = 0;

void newCarEntry(void);
void carExited(void);
void updateSevenSeg(s8 num);
void updateStatusLED(void);

void main(void)
{
	// initialize LEDs
	// Red LED	
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN0); // red
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN1); // green
	
	// initialize SSs
	SS_voidSevenSegInit(DIO_PORTB); // units
	SS_voidSevenSegInit(DIO_PORTC); // tens
	
	// initialize buttons
	BTN_voidButtonInit(DIO_PORTA, DIO_PIN2); // INC button
	BTN_voidButtonInit(DIO_PORTA, DIO_PIN3); // DEC button
	
	// display zeros on 7 segment
	SS_voidDisplayNumber(DIO_PORTB, SS_ZERO);
	SS_voidDisplayNumber(DIO_PORTC, SS_ZERO);
	
    while(TRUE)
    {
		newCarEntry();
		_delay_ms(100);
		carExited();
		_delay_ms(100);
    }
}

void newCarEntry(void)
{
	u8 incButtonEntry = BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN2);
	if (incButtonEntry == BTN_PRESSED)
	{
		_delay_ms(25);
		incButtonEntry = BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN2);
		if (incButtonEntry == BTN_PRESSED)
		{
			while (incButtonEntry == BTN_PRESSED)
				incButtonEntry = BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN2);
			if (carCount < MAX_CAR_COUNT)
			{
				carCount++;
				updateSevenSeg(carCount);
			}
		}			
	}
	updateStatusLED();
}

void carExited(void)
{
	u8 decButtonEntry = BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN3);
	if (decButtonEntry == BTN_PRESSED)
	{
		_delay_ms(25);
		decButtonEntry = BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN3);
		if (decButtonEntry == BTN_PRESSED)
		{
			while (decButtonEntry == BTN_PRESSED)
				decButtonEntry = BTN_u8IsButtonPressed(DIO_PORTA, DIO_PIN3);
			if (carCount > 0)
			{
				carCount--;
				updateSevenSeg(carCount);
			}
		}
	}
	updateStatusLED();
}

void updateSevenSeg(s8 num)
{
	u8 carCountArr[2] = {0};
	u8 digitsStored = 0;
	while (num)
	{
		carCountArr[digitsStored] = num  % 10;
		num /= 10;
		digitsStored++;
	}
	
	u8 i;
	u8 SS_Port = DIO_PORTB;
	for (i = 0; i < digitsStored; i++)
	{
		switch (carCountArr[i])
		{
			case 0: SS_voidDisplayNumber(SS_Port, SS_ZERO); break;
			case 1: SS_voidDisplayNumber(SS_Port, SS_ONE); break;
			case 2: SS_voidDisplayNumber(SS_Port, SS_TWO); break;
			case 3: SS_voidDisplayNumber(SS_Port, SS_THREE); break;
			case 4: SS_voidDisplayNumber(SS_Port, SS_FOUR); break;
			case 5: SS_voidDisplayNumber(SS_Port, SS_FIVE); break;
			case 6: SS_voidDisplayNumber(SS_Port, SS_SIX); break;
			case 7: SS_voidDisplayNumber(SS_Port, SS_SEVEN); break;
			case 8: SS_voidDisplayNumber(SS_Port, SS_EIGHT); break;
			case 9: SS_voidDisplayNumber(SS_Port, SS_NINE); break;
		}
		SS_Port = DIO_PORTC;
	}
}

void updateStatusLED(void)
{
	if (carCount == MAX_CAR_COUNT)
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTA, DIO_PIN0, LED_SINGLE_ON);
		LED_voidTurnSingleLEDOnOff(DIO_PORTA, DIO_PIN1, LED_SINGLE_OFF);
	}
	else
	{
		LED_voidTurnSingleLEDOnOff(DIO_PORTA, DIO_PIN1, LED_SINGLE_ON);
		LED_voidTurnSingleLEDOnOff(DIO_PORTA, DIO_PIN0, LED_SINGLE_OFF);
	}
}