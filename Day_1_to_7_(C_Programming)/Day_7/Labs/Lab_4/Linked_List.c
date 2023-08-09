#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

static node* createNode(void);
node *head = NULL;

static node* createNode(void){
	
	return (node*)malloc(sizeof(node));
}



void addNode(s32 value){
	node* new = createNode();
	new->data = value;
	new->next_node = NULL;
	
	if(head == NULL){
		head = new;
	}
	
	else{
		node *temp = head;
		
		while(temp->next_node != NULL){
			temp = (temp->next_node);
		}
		
		temp->next_node = new;
	}
	
	
}



void printLinkedList(void){
	
	if(head == NULL){
		printf("Linked list is empty....!!!");
	}
	
	else{
		u32 i=0;
		node *temp = head;
		while(temp != NULL){
			i++;
			printf("\nNode number -%d = %d", i, temp-> data);
			temp = (temp->next_node);
		}
		
	}
	
}