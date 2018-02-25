#include "..\Lib\tree_structure.h"
#include <stdlib.h>
void main(){
	
	node_t *head=NULL;
	int arr[7] = {1,2,3,4,5,6,7};
	insertSortedArrayToBST(&head,arr,0,6);
	insertNode(7,&head);
	insertNode(8,&head);
	insertNode(9,&head);
	printPreOrderNode(head);
	
	commanParentOfTwoNodes(9,5,head,head,head);
	//printf("Search : %d",searchNode(30,&head));
}