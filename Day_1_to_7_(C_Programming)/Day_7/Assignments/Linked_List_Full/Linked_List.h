#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "STD_Types.h"

/** #Indexing from 1 to list_size# */

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

// Sorting
s8 linkedList_sort_ascendingly(void); // sort_ascendingly
s8 linkedList_sort_descendingly(void); // sort_descendingly

// General-purpose
s32 linkedList_size(void); // size
s8 linkedList_isEmpty(void); // is_empty
s8 linkedList_print(void); // print_list
s8 linkedList_isInList(s32 value); // is_in_list => returns the index if yes : returns -1 if no

#endif