#include "..\Lib\tree_structure.h"
#include <stdlib.h>
void main(){
	
	node_t *head=NULL;
	insertNode(10,&head);
	insertNode(20,&head);
	insertNode(30,&head);
	printPreOrderNode(head);
	//printf("Search : %d",searchNode(30,&head));
}