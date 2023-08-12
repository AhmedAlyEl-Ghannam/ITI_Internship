#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"


// defining crucial global variables
node* head = NULL;
s32 list_size = 0;

/********** Auxiliary Functions **********/

static node* createNode(void)
{
	return (node*)malloc(sizeof(node));
}

void swap_nodes(node* node1, node* node2)
{
	if ((node1 == NULL) || (node2 == NULL))
		printf("What the Actual Duck?!\n");
	
	(node1->data) ^= (node2->data);
	(node2->data) ^= (node1->data);
	(node1->data) ^= (node2->data);
}

u8 compare_data(s32 data1, s32 data2, u8 comp_flag) 
{
	return ( comp_flag == 0 ? (data1 > data2) : (data1 < data2) );
}

struct node* linkedList_traverseToIndex(u16 index)
{
	// check index validity
	if ((index < 0) || (index > list_size))
		return NULL; // indices out of bounds are prohibited
	
	// check list population
	if (linkedList_isEmpty() == -5)
		return NULL; // trying to remove node from an empty list is prohibited
	
	struct node* iterator = head;
	int i;
	for (i = 0; i < index; i++)
		iterator = (iterator->next_node);
	return iterator;
}

/********** End of Auxiliary Functions **********/

/**************************************************/

/********** Add Node Functions **********/

s8 linkedList_addNode_atIndex(s32 value, u16 index)
{
	// check index validity
	if ((index < 0) || (index > list_size))
		return -1; // indicates that index is out of bounds
	
	node* dumDumNode = NULL;
	dumDumNode = createNode();
	
	// check if node was created successfully
	if (dumDumNode == NULL)
		return -2; // indicates that memory allocation was not successful
	
	dumDumNode->data = value;
	dumDumNode->next_node = NULL;
	
	if(index == 0) // first node in the list
	{
		if (head == NULL) // uninitialized head means that it's the start of a new list
		{
			dumDumNode->next_node = NULL;
			head = dumDumNode;
		}
		else
		{
			dumDumNode->next_node = head;
			head = dumDumNode;
		}
	}
	else
	{
		node* temp = head;
		
		while (--index) // keep looping until you reach the node @ index
			temp = (temp->next_node);
		
		// temp is now the node @ the index
		// dumDumNode->next_node = *old node's next node*
		// temp->next_node = dumDumNode
		dumDumNode->next_node = temp->next_node;
		temp->next_node = dumDumNode;
	}
	
	list_size++;
	
	return 1; // indicates normal behaviour
}

s8 linkedList_addNode_first(s32 value)
{
	return linkedList_addNode_atIndex(value, 0);
}

s8 linkedList_addNode_last(s32 value)
{
	return ( (list_size == 0) ? linkedList_addNode_atIndex(value, 0) : linkedList_addNode_atIndex(value, list_size - 1) );
}

/********** End of Add Node Functions **********/

/**************************************************/

/********** Remove Node Functions **********/

s8 linkedList_removeNode_atIndex(u16 index)
{
	// check index validity
	if ((index < 0) || (index > list_size))
		return -1; // indicates that index is out of bounds
	
	// check list population
	if (linkedList_isEmpty() == -5)
		return -3; // trying to remove node from an empty list
	
	 // store head OG address in temp -> frees this address if index = 0
	struct node* temp = head;
	struct node* previous = NULL;

	// delete the first node
	if (index == 0) // update head node
		head = head->next_node;
	else
	{		
		while (index--) // keep looping until you reach the node @ index (stored in temp)
		{
			previous = temp;
			temp = (temp->next_node);
		}
	
		previous->next_node = temp->next_node;
	}
	
	free(temp); // to prevent memory leaks
	temp = NULL; // to prevent dangling pointers
	
	list_size--;
	
	return 1; // indicates normal behaviour
}

s8 linkedList_removeNode_byValue(s32 value)
{
	s32 is_in_list = linkedList_isInList(value);
	
	switch (is_in_list)
	{
		case -7: return -3; // empty list -> cannot remove an node from an empty list
		case -8: return -9; // not found -> no node with such value exist
	}
	
	return linkedList_removeNode_atIndex((u16)is_in_list);
}

s8 linkedList_removeNode_first(void)
{
	return linkedList_removeNode_atIndex(0);
}

s8 linkedList_removeNode_last(void)
{
	return linkedList_removeNode_atIndex(list_size - 1);
}

/********** End of Remove Node Functions **********/

/**************************************************/

/********** Sorting Function **********/

s8 linkedList_sort(u8 sort_order_flag) // =0 for ascending : =1 for descending
{
	if (linkedList_isEmpty() == -5) // empty list
		return -4; // trying to sort an empty list
	else if (list_size == 1)
		return 0; // trying to sort a list that contains only one element
	else // list larger than 2
	{
		// loop iterators
		int i, j;
		// list iterators
		struct node* iterator_i = NULL;
		struct node* iterator_j = NULL;
		
		// bubble sort (tried this way with iterators---kinda like it ngl)
		for (i = 0; i < list_size; i++)
		{
			iterator_i = linkedList_traverseToIndex(i);
			for (j = i + 1; j < list_size; j++)
			{
				iterator_j = linkedList_traverseToIndex(j);
				if (compare_data(iterator_i->data, iterator_j->data, sort_order_flag))
					swap_nodes(iterator_i, iterator_j);
			}
		}
	}
	
	return 1; // indicates normal behaviour
}

/********** End of Sorting Function **********/

/**************************************************/

/********** General-purpose Functions **********/

s32 linkedList_size(void)
{
	return list_size;
}

s8 linkedList_isEmpty(void)
{
	return ( (linkedList_size() < 1) ? -5 : 5 ); // return 5 for populated list and -5 for empty list
}

s8 linkedList_print(void)
{
	if (linkedList_isEmpty() == -5)
		return -6; // trying to print an empty list
	
	u16 i;
	node* temp = head;
	
	printf("\t\t\t[ ");
	for (i = 0; i < list_size; i++)
	{
		printf("%d ", temp-> data);
		temp = (temp->next_node);
	}
	printf("]");
			
	return 1; // indicates normal behaviour
}

s32 linkedList_isInList(s32 value)
{
	if (linkedList_isEmpty() == -5)
		return -7; // trying to check for the existance of value in an empty list
	
	node* temp = head;
	
	u8 is_in_list = 0;
	u16 index_counter = 0;
	struct node* iterator_i = NULL;
	
	for (index_counter = 0; index_counter < list_size; index_counter++)
	{
		iterator_i = linkedList_traverseToIndex(index_counter);
		if (iterator_i != NULL)
		{
			if ((iterator_i->data) == value)
			{
				is_in_list ^= 1; // raise flag
				break;
			}
		}
		
	}
		
	if (is_in_list)
		return index_counter;
	else
		return -8; // indicates that no nodes were found with this value
}

/********** End of General-purpose Functions **********/

/**************************************************/