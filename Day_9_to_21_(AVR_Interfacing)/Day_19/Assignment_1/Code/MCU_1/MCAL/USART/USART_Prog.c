#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_Types.h"
#include "USART_Register.h"
#include "USART_Private.h"
#include "USART_CFG.h"
#include "USART_Interface.h"

//void USART_voidInit(u16 copy_u16Baud)
void USART_voidInit(void)
{
	u8 local_u8UCSRC = USART_UCSRC_MASK;
	// #notice that the value put in UBRR
	// depends on mcu clock frequency#
	/*the value 51 is for 9600 Baud @8MHz*/
	/**set baud rate*/
	UBRRL = (u8)(51);
	UBRRH = (u8)(51 >> 8);
	
	/**select normal speed*/
	CLR_BIT(UCSRA, USART_UCSRA_U2X);
	
	/**disable multiprocessor mode*/
	CLR_BIT(UCSRA, USART_UCSRA_MPCM);
	
	/**enable transmitter && receiver*/
	SET_BIT(UCSRB, USART_UCSRB_RXEN);
	SET_BIT(UCSRB, USART_UCSRB_TXEN);
	
	/**select data length (8-bit by default)*/
	CLR_BIT(UCSRB, USART_UCSRB_UCSZ2);
	SET_BIT(local_u8UCSRC, USART_UCSRC_UCSZ1);
	SET_BIT(local_u8UCSRC, USART_UCSRC_UCSZ0);
	
	/**choose mode: asynchronous or synchronous*/
	/**for async: 2 mcus agree on a baud rate*/
	/**for sync: 2 mcus run on the same CLOCK*/
	CLR_BIT(local_u8UCSRC, USART_UCSRC_UMSEL);
	
	/**disable parity*/
	CLR_BIT(local_u8UCSRC, USART_UCSRC_UPM1);
	CLR_BIT(local_u8UCSRC, USART_UCSRC_UPM0);
	
	/**set 2 stop bits*/
	SET_BIT(local_u8UCSRC, USART_UCSRC_USBS);
	
	/**disable clock polarity*/
	CLR_BIT(local_u8UCSRC, USART_UCSRC_UCPOL);
	
	/***/
	UCSRC = local_u8UCSRC;
	
}

void USART_voidSendData(u8 copy_u8Data)
{
	/**wait for empty transmit buffer*/
	while (GET_BIT(UCSRA, USART_UCSRA_UDRE) == 0);
	
	/**put data in buffer*/
	UDR = copy_u8Data;
}

u8 USART_u8ReceiveData(void)
{
	/**wait for data to be received*/
	while (GET_BIT(UCSRA, USART_UCSRA_RXC) == 0);
	
	/**get and return received data from buffer*/
	return UDR;
}