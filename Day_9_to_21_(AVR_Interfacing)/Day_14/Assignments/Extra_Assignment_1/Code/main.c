/*
 * main.c
 *
 * Created: 8/17/2023 6:47:42 PM
 *  Author: Ahmed
 */ 

#define F_CPU 8000000
#include <util/delay.h>
#include "MCAL/DIO/DIO_Prog.c"
#include "MCAL/EXTI/EXTI_Prog.c"
#include "HAL/SEVEN_SEGMENT/SS_Prog.c"
#include "HAL/LED/LED_Prog.c"
#include "HAL/BUTTON/BUTTON_Prog.c"

#define TRUE 1
#define MAX_CAR_COUNT 25

void ISR_INT0(void);
void ISR_INT1(void);

volatile s8 carCount = 0;

volatile static u8 global_u8Flag = 0;

static void updateSevenSeg(s8 num);
static void updateStatusLED(void);

void main(void)
{
	// initialize LEDs
	// Red LED	
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN0); // red
	LED_voidLEDSingleInit(DIO_PORTA, DIO_PIN1); // green
	
	// initialize SSs
	SS_voidSevenSegInit(DIO_PORTB); // units
	SS_voidSevenSegInit(DIO_PORTC); // tens
	
	// display zeros on 7 segment
	SS_voidDisplayNumber(DIO_PORTB, SS_ZERO);
	SS_voidDisplayNumber(DIO_PORTC, SS_ZERO);
	
	// interrupt switch initialization
	BTN_voidButtonInit(DIO_PORTD, DIO_PIN2); // inc
	BTN_voidButtonInit(DIO_PORTD, DIO_PIN3); // dec
	// interrupt initialization
	sei();
	EXTI_voidEnableInterrupt(EXTI_GICR_INT0);
	EXTI_voidEnableInterrupt(EXTI_GICR_INT1);
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT0);
	EXTI_voidSetSignalSenseMode(EXTI_SENSE_RISING_EDGE, EXTI_GICR_INT1);
	EXTI_voidSetCallBack(ISR_INT0, EXTI_INT0);
	EXTI_voidSetCallBack(ISR_INT1, EXTI_INT1);
	
	// test LED
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN6, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN7, DIO_PIN_OUTPUT);
	
    while(TRUE)
    {
		updateSevenSeg(carCount);
		updateStatusLED();
    }
}

void ISR_INT0(void)
{
	if (carCount < MAX_CAR_COUNT)
		carCount++;
}
void ISR_INT1(void)
{
	if (carCount > 0)
		carCount--;
}

static void updateSevenSeg(s8 num)
{
	u8 carCountArr[2] = {0};
	u8 carCountUnits = 0;
	u8 carCountTens = 0;
	
	carCountUnits = num  % 10;
	num /= 10;
	carCountTens = num  % 10;
		
	carCountArr[0] = carCountUnits;
	carCountArr[1] = carCountTens;
	
	u8 i;
	u8 SS_Port = DIO_PORTB;
	for (i = 0; i < 2; i++)
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

static void updateStatusLED(void)
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