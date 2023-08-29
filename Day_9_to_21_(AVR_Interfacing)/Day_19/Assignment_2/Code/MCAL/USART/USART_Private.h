#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#define USART_UCSRC_MASK	0x80


//UCSRA => control && status register A
#define USART_UCSRA_RXC 	7//=> receive complete (generates interrupt)
#define USART_UCSRA_TXC 	6//=> transmit complete (generates interrupt)
#define USART_UCSRA_UDRE	5//=> data register empty (generates interrupt)
#define USART_UCSRA_FE		4//=> frame error
#define USART_UCSRA_DOR		3//=> data overrun
#define USART_UCSRA_PE		2//=> parity error
#define USART_UCSRA_U2X		1//=>
#define USART_UCSRA_MPMC	0//=> set to 0

//UCSRB
#define USART_UCSRB_RXCIE	7//=> 1 to enable Rx interrupt
#define USART_UCSRB_TXCIE	6//=> 1 to enable Tx interrupt
#define USART_UCSRB_UDRIE	5
#define USART_UCSRB_RXEN	4//=> 1 to enable Rx
#define USART_UCSRB_TXEN	3//=> 1 to enable Tx
#define USART_UCSRB_UCSZ2	2//=>to hold the 9th bit
#define USART_UCSRB_RXB8	1
#define USART_UCSRB_TXB8	0

//UCSRC
// UCSRC has the same address of another register so write bit 7 to 1 everytime you write any of its bits
#define USART_UCSRC_URSEL	7//=> this bit MUST BE 1 every time you write to any of these nibbas
#define USART_UCSRC_UMSEL	6
#define USART_UCSRC_UPM1	5
#define USART_UCSRC_UPM0	4
#define USART_UCSRC_USBS	3
#define USART_UCSRC_UCSZ1	2
#define USART_UCSRC_UCSZ0	1
#define USART_UCSRC_UCPOL	0

//UBRRL && UBRRH


#endif