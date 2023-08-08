#include <stdio.h>
#include <stdlib.h>

/**
	Assignment Description
		Write C code that manage a small school. The school
		has 3 classes each class contains 10 students. Define
		three arrays for the three classes each one with a length
		of 10. Save a random numbers in all array elements to 
		indicate the students grade. The program will calculate 
		and display the following statistics: 
			1- Number of passed students 
			2- Number of Failed students 
			3- Highest grade 
			4- Lowest grade 
			5- Average grade 
		Knowing that the total grade is from 100 and the minimum
		passing grade is 50.

*/

void main(void)
{
	// stored them in an array just in case they were needed kater on
	int classes[3][10] = {{0}};
	int sum[3] = {0};
	int min[3] = {100, 100, 100};
	int max[3] = {0};
	int no_of_passed[3] = {0};
	int no_of_failed[3] = {0};
	
	int max_classes = 0;
	int min_classes = 100;
	int sum_classes = 0;
	int passed_classes = 0;
	int failed_classes = 0;
	
	int i, j, k;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			classes[i][j] = rand() % 100 + 1;
			sum[i] += classes[i][j];
			
			if (classes[i][j] >= 50)
				no_of_passed[i]++;
			else
				no_of_failed[i]++;
			
			if (max[i] < classes[i][j])
				max[i] = classes[i][j];
			
			if (min[i] > classes[i][j])
				min[i] = classes[i][j];
		}	
		printf("Number of passed students in class %d = %d\n", i+1, no_of_passed[i]);
		printf("Number of failed students in class %d = %d\n", i+1, no_of_failed[i]);
		printf("Max Grade in class %d = %d\n", i+1, max[i]);
		printf("Min Grade in class %d = %d\n", i+1, min[i]);
		printf("Average Grade in class %d = %0.1f\n", i+1, sum[i] / 10.0);
		printf("\n\n");
		sum_classes += sum[i];
		passed_classes += no_of_passed[i];
		failed_classes += no_of_failed[i];
		
		if (max_classes < max[i])
			max_classes = max[i];
		
		if (min_classes > min[i])
			min_classes = min[i];
	}
	
	printf("Number of passed students in school = %d\n", passed_classes);
	printf("Number of failed students in school = %d\n", failed_classes);
	printf("Max Grade in school = %d\n", max_classes);
	printf("Min Grade in school = %d\n", min_classes);
	printf("Average Grade in school = %0.1f\n", sum_classes / 10.0);
	
}
