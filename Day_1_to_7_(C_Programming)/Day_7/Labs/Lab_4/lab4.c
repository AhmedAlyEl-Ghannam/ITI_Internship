#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

void main(void)
{
	linkedList* myLinkedList = linkedList_init();
	
	u8 choice = 0;
	
	printf("1. Add a node at the end\n");
	printf("2. Add a node at index\n");
	printf("3. Remove a node at the end\n");
	printf("4. Remove a node at index\n");
	printf("5. Print the linked list\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");
	scanf("%hhd", &choice);
	
	switch (choice)
	{
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: break;
		case 6: break;
		default:
			
	}
	
}


