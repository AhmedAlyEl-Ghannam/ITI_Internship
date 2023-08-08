#include <stdio.h>

typedef unsigned char u8;

void set_bit(u8* var, u8 bit_pos);
void clr_bit(u8* var, u8 bit_pos);
void tog_bit(u8* var, u8 bit_pos);

void main(void) 
{
	u8 x = 0b00000111; // 0x17
	
	set_bit(&x, 4);
	
	printf("%u\n", x);
	
	tog_bit(&x, 0);
	
	printf("%u\n", x);
	
	clr_bit(&x, 2);
	
	printf("%u\n", x);
}

void set_bit(u8* var, u8 bit_pos)
{
	(*var) |= (1 << bit_pos);
}

void clr_bit(u8* var, u8 bit_pos)
{
	(*var) &= ~(1 << bit_pos);
}

void tog_bit(u8* var, u8 bit_pos)
{
	(*var) ^= (1 << bit_pos);
}