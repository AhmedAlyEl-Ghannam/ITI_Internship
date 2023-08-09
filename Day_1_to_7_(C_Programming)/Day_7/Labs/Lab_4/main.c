#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

void main (void){
	
	u8 input;
	s32 newData;
	u8 exitFlag = 0;
	
	while(exitFlag == 0){
		printf("\nTo add node press 0 ");
		printf("\nTo print linked list press 1");
		printf("\nTo Exit press 2");
		printf("\nYour choice: ");
		scanf("%d", &input);
		
		switch(input){
			
			case 0: printf("pls enter node value: ");
					scanf("%d",&newData);
					addNode(newData);
					printf("node added..!!"); break;
			
			case 1: printLinkedList(); break;
			
			case 2: printf("thx ...!!"); exitFlag =1; break;
			
			default: printf(" wrong entry..!!!");
	
		}
		
	}
	
	

	
	
}