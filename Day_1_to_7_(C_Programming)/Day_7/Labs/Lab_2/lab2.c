#include <stdio.h>
#include "Bit_Math.h"
#include "STD_Types.h"

void main(void)
{
	u8 x = 0b10010111; // 0x97
	
	SET_BIT(x, 3);
	printf("%d\n", x); // 0x9F
	
	CLR_BIT(x, 0);
	printf("%d\n", x); // 0x9E
	
	TOG_BIT(x, 2);
	printf("%d\n", x); // 0x9A
	
	printf("%d\n", GET_BIT(x, 7)); // 1
}