#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include "STD_Types.h"


typedef struct node
{
	s32 data;
	struct node* next_node;
} st_node;

typedef struct
{
	u8 size;
	st_node* head;
	st_node* end;
} linkedList;

linkedList* linkedList_init(void);

void linkedList_addNode(linkedList* dumDumLinkedList);

void linkedList_addNode_at_index(linkedList* dumDumLinkedList, u8 index);

#endif