#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

linkedList* linkedList_init(void)
{
	linkedList* dumDumLinkedList = NULL;
		
	dumDumLinkedList->head = NULL;
	dumDumLinkedList->head->next_node = NULL;
	
	dumDumLinkedList->size = 0;
	
	return dumDumLinkedList;
}

void linkedList_addNode_at_index(linkedList* dumDumLinkedList, u8 index)
{
	if (dumDumLinkedList == NULL)
	{
		printf("Invalid Linked List Pointer!\n");
		return;
	}
	
	st_node* dumDumNode = NULL;
	dumDumNode = (st_node*)malloc(sizeof(dumDumNode));
	
	if (dumDumNode == NULL)
	{
		printf("Unable to create a node!\n");
		return;
	}
	
	if (size == 0)
	{
		printf("Enter a value: ");
		scanf("%d", dumDumNode);
		dumDumLinkedList->head = dumDumNode;
		(dumDumLinkedList->size)++;
		
	}
}

void linkedList_addNode(linkedList* dumDumLinkedList)
{
	linkedList_addNode_at_index(dumDumLinkedList, (dumDumLinkedList->size))
}