#include "../../MCAL/DIO/DIO_CFG.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Keypad_CFG.h"
#include "Keypad_Private.h"
#include "Keypad_Interface.h"

void KPD_voidInit(void)
{
	u8 local_u8Iterator;
	for (local_u8Iterator = DIO_PIN0; local_u8Iterator <= DIO_PIN7; local_u8Iterator++)
	{
		if (local_u8Iterator <= KPD_ROW_PIN4)
			DIO_voidSetPinDirection(KPD_PORT, local_u8Iterator, DIO_PIN_INPUT);
		
		if (local_u8Iterator <= KPD_COL_PIN4)
			DIO_voidConfigurePinPullUpRes(KPD_PORT, local_u8Iterator, DIO_PIN_PULLUP_ENABLED);
	}
}

u8 KPD_u8GetPressedKey(void)
{
	u8 local_u8Iterator1;
	u8 local_u8Iterator2;
	for (local_u8Iterator1 = KPD_COL_PIN1; local_u8Iterator1 <= KPD_COL_PIN4; local_u8Iterator1++)
	{
		// disable pull-up here
		DIO_voidConfigurePinPullUpRes(KPD_PORT, local_u8Iterator1, DIO_PIN_PULLUP_DISABLED);
		for (local_u8Iterator2 = KPD_ROW_PIN1; local_u8Iterator2 <= KPD_ROW_PIN4; local_u8Iterator2++)
		{
			// read pin
			if (DIO_u8GetPinValue(KPD_PORT, local_u8Iterator2) == KPD_BUTTON_PRESSED)
			{
				_delay_ms(25); // debouncing protecc
				if (DIO_u8GetPinValue(KPD_PORT, local_u8Iterator2) == KPD_BUTTON_PRESSED)
				{
					// handling long pressing
					while (!DIO_u8GetPinValue(KPD_PORT, local_u8Iterator2));
					return KPD_u8CharArr[local_u8Iterator1][local_u8Iterator2];
				}
			}
		}
		// enable pull-up again
		DIO_voidConfigurePinPullUpRes(KPD_PORT, local_u8Iterator1, DIO_PIN_PULLUP_ENABLED);
	}
	
	return 0x00; // no key pressed
}