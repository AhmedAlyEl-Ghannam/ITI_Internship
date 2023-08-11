#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

s16 menu(void);
void return_type_handler(s32 return_value);

void main(void)
{
	
	u8 is_running = 1;
	s32 value= 0;
	s32 index = 0;
	
	
	while (is_running)
	{
		switch (menu())
		{
			case 1 : 	printf("\nEnter a value to insert at the beginning: ");
						scanf("%d", &value);
						value = linkedList_addNode_first(value);
						return_type_handler(value);
						break;
						
			case 2 : 	printf("\nEnter a value: ");
						scanf("%d", &value);
						printf("Enter an index: ");
						scanf("%d", &index);
						value = linkedList_addNode_atIndex(value, index);
						return_type_handler(value);
						break;
			
			case 3 : 	printf("\nEnter a value to insert at the end: ");
						scanf("%d", &value);
						value = linkedList_addNode_last(value);
						return_type_handler(value);
						break;
			
			
			case 4 : 	value = linkedList_removeNode_first();
						return_type_handler(value);
						break;
						
			case 5 : 	printf("\nEnter an index: ");
						scanf("%d", &index);
						value = linkedList_removeNode_atIndex(index);
						return_type_handler(value);
						break;
						
			case 6 : 	printf("\nEnter a value to delete: ");
						scanf("%d", &value);
						value = linkedList_removeNode_byValue(value);
						return_type_handler(value);
						break;			
						
			case 7 : 	value = linkedList_removeNode_last();
						return_type_handler(value);
						break;
						
			case 8 : 	value = linkedList_sort_ascendingly();
						return_type_handler(value);
						break;
						
			case 9 : 	value = linkedList_sort_descendingly();
						return_type_handler(value);
						break;
						
			case 10: 	printf("\n\t\t\tSize of List = %d\n", linkedList_size());
						break;
						
			case 11: 	value = linkedList_isEmpty();
						return_type_handler(value);
						break;
						
			case 12: 	printf("\nEnter a value to search for: ");
						scanf("%d", &value);
						index = linkedList_isInList(value);
						if (index == -8)
							return_type_handler(index);
						else
							printf("\t\t\tValue was found at node %hhd\n", index);
						break;
						
			case 13: 	value = linkedList_print();
						return_type_handler(value);
						break;
						
			case 14: 	printf("\nEnter an index: ");
						scanf("%d", &index);
						struct node* temp = linkedList_traverseToIndex(index);
						printf("\t\t\tNode at Index %d = %d", index, temp->data);
						break;
						
			
			case 15: 	is_running ^= 1;
						break;
						
			default:	printf("\n\t\t\tInvalid Input! Try Again\n");
			
		}
	}
}

s16 menu(void)
{
	s16 choice = 0;
	
	printf("\n\n");
	printf("01. Add a node at the beginning\n");
	printf("02. Add a node at index\n");
	printf("03. Add a node at the end\n");
	printf("04. Remove a node at the beginning\n");
	printf("05. Remove a node at index\n");
	printf("06. Remove a node by value\n");
	printf("07. Remove a node at the end\n");
	printf("08. Sort list ascendingly\n");
	printf("09. Sort list descendingly\n");
	printf("10. Print the size of list\n");
	printf("11. Tell me if list is empty\n");
	printf("12. Tell me if value is in list\n");
	printf("13. Print the linked list\n");
	printf("14. Print node value by index\n");
	printf("15. Exit\n");

	printf("\nEnter your choice: ");
	scanf("%hd", &choice);
	
	return choice;
}

void return_type_handler(s32 return_value)
{
	printf("\n\n");
	//no node with such value exist
	switch(return_value)
	{
		case -9:	printf("\t\t\tCannot Remove Node Because There is no Node with Such Value\n");
					break;
		case -8:	printf("\t\t\tCannot Find a Node with Such Value\n");
					break;
		case -7: 	printf("\t\t\tCannot Find a Node in an Empty List\n");
					break;
		case -6: 	printf("\t\t\tCannot Print an Empty List\n"); 						
					break;
		case -5: 	printf("\t\t\tList is Empty\n"); 									
					break;
		case -4: 	printf("\t\t\tUnable to Sort an Empty List\n"); 						
					break;
		case -3: 	printf("\t\t\tNode Removal from an Empty List is Prohibited\n"); 	
					break;
		case -2: 	printf("\t\t\tMemory Allocation was not Successful\n"); 				
					break;
		case -1: 	printf("\t\t\tOut of Bounds: Invalid Index\n"); 						
					break;
		case  0: 	printf("\t\t\tCannot Sort a List with Size 1\n"); 					
					break;
		case  1: 	printf("\t\t\tCommand Executed Successfully\n"); 					
					break;
		case  5: 	printf("\t\t\tList is Populated\n"); 								
					break;
	}
}


