#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "STD_Types.h"

/** #Indexing from 0 to list_size-1# */

// Errors defined as enum
typedef enum linkedList_errorCode
{
	NO_NODE_TO_REMOVE = -9, 
	NO_NODE_FOUND = -8,
	SEARCH_EMPTY_LIST = -7,
	PRINT_EMPTY_LIST = -6,
	EMPTY_LIST = -5,
	UNSORTABLE_LIST = -4,
	REMOVE_NODE_FROM_EMPTY_LIST = -3,
	UNSUCCESSFUL_MEM_ALLOC = -2,
	INVALID_INDEX = -1,
	SORT_SINGLE_NODE = 0,
	SUCCESSFUL_OPERATION = 1,
	POPULATED_LIST = 5
} linkedList_Error;

// defining node struct
typedef struct node
{
	s32 data;
	struct node* next_node;
} node;

/**
 *	AUXILIARY METHODS
 */
 
static node* createNode(void);
void swap_nodes(node* node1, node* node2);
struct node* linkedList_traverseToIndex(u16 index); // iterates over list and returns node at index
u8 compare_data(s32 data1, s32 data2, u8 comp_flag); // comparison func for ascending/descending bubble sort 

/**
 *	MAIN METHODS
 */
 
// Add Node
s8 linkedList_addNode_atIndex(s32 value, u16 index); // add_at_index
s8 linkedList_addNode_first(s32 value); // add_first
s8 linkedList_addNode_last(s32 value); // add_last

// Remove Node
s8 linkedList_removeNode_atIndex(u16 index); // remove_at_index
s8 linkedList_removeNode_first(void); // remove_first
s8 linkedList_removeNode_last(void); //remove_last
s8 linkedList_removeNode_byValue(s32 value); // remove_by_value

// Sorting
s8 linkedList_sort(u8 sort_order_flag);

// General-purpose
s32 linkedList_size(void); // size
s8 linkedList_isEmpty(void); // is_empty
s8 linkedList_print(void); // print_list
s32 linkedList_isInList(s32 value); // is_in_list => returns the index if yes : returns -1 if no

#endif