#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "STD_Types.h"

struct node{
	s32 data;
	struct node *next_node;
};

typedef struct node node;

void addNode(s32 value);
void printLinkedList(void);



#endif