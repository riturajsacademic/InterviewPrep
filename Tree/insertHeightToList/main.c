#include "..\Lib\tree_structure.h"
#include <stdlib.h>
#include <stdio.h>
void main(){
	
	node_t *head=NULL;
	int arr[7] = {1,2,3,4,5,6,7};
	insertSortedArrayToBST(&head,arr,0,6);
	printPreOrderNode(head);
	
	//printf("Height  : %d",maxDepth(head));
	int height = maxDepth(head);
	int iterator=0;
	
	for(iterator=0;iterator<height;iterator++){
		insertList(&head,iterator);
	}
	
	
}