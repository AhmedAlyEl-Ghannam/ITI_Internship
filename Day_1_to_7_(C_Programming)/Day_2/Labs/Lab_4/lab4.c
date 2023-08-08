#include <stdio.h>

void main(void)
{
	int grade;
	printf("Please enter your grade: ");
	scanf("%d", &grade);
	
	if ((grade > 100) || (grade < 0))
		printf("Invalid grade.\n");
	else if ((grade >= 0) && (grade < 50))
		printf("Failed\n");
	else if ((grade >= 50) && (grade < 65))
		printf("Normal\n");
	else if ((grade >= 65) && (grade < 75))
		printf("Good\n");
	else if ((grade >= 75) && (grade < 85))
		printf("Very Good\n");
	else // grade >= 85
		printf("Excellent\n");
}