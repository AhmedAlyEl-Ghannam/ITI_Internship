#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Private.h"
#include "LCD_CFG.h"
#include "LCD_Interface.h"
#include <util/delay.h>

void LCD_voidInitDisplay(void)
{
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_CTRL_RW, DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_PIN_OUTPUT);
	
	#if (LCD_MODE_OF_OPERATION == LCD_4BIT_MODE)
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN0, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN1, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN2, DIO_PIN_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT, LCD_DATA_PIN3, DIO_PIN_OUTPUT);
	#elif (LCD_MODE_OF_OPERATION == LCD_8BIT_MODE)
		DIO_voidSetPortDirection(LCD_DATA_PORT, DIO_PORT_OUTPUT);
	#endif
	
	#if (LCD_MODE_OF_OPERATION == LCD_4BIT_MODE)
		LCD_voidSendCMD(0b000010000);
		_delay_us(50);
		LCD_voidSendCMD(0b000010000);
		_delay_us(50);
	#endif
	LCD_voidSendCMD(LCD_CMD_FUNCTION_SET);
	_delay_us(50);
	
	#if (LCD_MODE_OF_OPERATION == LCD_4BIT_MODE)
		LCD_voidSendCMD(0b000000000);
		_delay_us(50);
	#endif
	LCD_voidSendCMD(LCD_CMD_DISPLAY_ON_OFF);
	_delay_us(50);
	
	#if (LCD_MODE_OF_OPERATION == LCD_4BIT_MODE)
		LCD_voidSendCMD(0b000000000);
		_delay_ms(2);
	#endif
	LCD_voidSendCMD(LCD_CMD_DISPLAY_CLR);
	_delay_ms(2);
	
	#if (LCD_MODE_OF_OPERATION == LCD_4BIT_MODE)
		LCD_voidSendCMD(0b000000000);
		_delay_us(50);
	#endif
	LCD_voidSendCMD(LCD_CMD_ENTRY_MODE_SET);
	_delay_us(50);
}

void LCD_voidSendCMD(u8 copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_RS, DIO_PIN_LOW);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_RW, DIO_PIN_LOW);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_PIN_HIGH);
	DIO_voidSetPortValue(LCD_DATA_PORT, copy_u8Command);
	_delay_us(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT, LCD_CTRL_EN, DIO_PIN_LOW);
}

void LCD_voidClrDisplay(void)
{
	LCD_voidSendCMD(LCD_CMD_DISPLAY_CLR);
	_delay_ms(2);
}

void LCD_voidReturnHome(void)
{
	LCD_voidSendCMD(LCD_CMD_RETURN_HOME);
	_delay_ms(1);  
}