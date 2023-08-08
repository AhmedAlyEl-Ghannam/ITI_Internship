#include <stdio.h>
#include <stdlib.h> 
#include "STD_Types.h"

// rand() % 100 + 1;

typedef struct
{
	u16 math;
	u16 language;
	u16 physics;
	u16 chemistry;
} student;

void main(void)
{
	student students[10];
	int i;
	for (i = 0; i < 10; i++)
	{
		students[i].math = rand() % 100 + 1;
		students[i].language = rand() % 100 + 1;
		students[i].physics = rand() % 100 + 1;
		students[i].chemistry = rand() % 100 + 1;
	}
	
	u16 id;
	printf("Enter Student ID: ");
	scanf("%hd", &id);
	
	if (id >= 0 && id <= 9)
	{
		printf("Math Grade: %hd\n", students[id].math);
		printf("Language Grade: %hd\n", students[id].language);
		printf("Physics Grade: %hd\n", students[id].physics);
		printf("Chemistry Grade: %hd\n", students[id].chemistry);
	}
	else
		printf("Student ID is not correct\n");
}

