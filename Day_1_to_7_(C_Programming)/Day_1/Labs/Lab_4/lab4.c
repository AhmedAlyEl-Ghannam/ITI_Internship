#include <stdio.h>

void main(void)
{
	int x, y;
	x = 7; // 111
	y = 4; // 100
	
	printf("%d\n%d\n%d\n%d\n%d\n", x & y, x | y, x ^ y, x >> 1, y << 2);
	// 100 111 011 11 10000
	// 4    7   3  3  16
}