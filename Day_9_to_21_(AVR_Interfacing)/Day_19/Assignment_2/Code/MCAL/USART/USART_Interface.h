#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_voidInit(void);
void USART_voidSendData(u8 copy_u8Data);
u8 USART_u8ReceiveData(void);

#endif