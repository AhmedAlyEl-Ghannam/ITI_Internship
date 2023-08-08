#include <stdio.h>
#include <stdlib.h> 
#include "STD_Types.h"

typedef struct
{
	u16 x;
	u16 y;
	u32 z;
	u32 k;
} student;

void main(void)
{
	student x;
	printf("%d\n", sizeof(x));
	// before ascending order = 16
	// after ascending order = 12
}

