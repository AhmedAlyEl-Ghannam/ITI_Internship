#include <stdio.h>

void main(void)
{
	int hours = 0;
	int rate_per_hour = 50;
	printf("Please enter your working hours: ");
	scanf("%d", &hours);
	
	if (hours >= 40)
	{
		printf("Your salary is %d\n", hours * rate_per_hour);
	}
	else
	{
		printf("Your salary is %0.1f\n", hours * rate_per_hour * 0.9);
	}
}