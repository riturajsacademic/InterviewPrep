#include <stdio.h>
#include <stdlib.h>
/*
Question: Find if two LL intersect at one point or not.

1->2->3->5->6->7->/--
	  ^
     /
2->4

1. find length of linked list L1 and L2. 

L1 = lengthOfList();
L2 = lengthOfList();

2. if one is less than the other remove that from the longer list, and start incrementing by one.
*/
typedef struct node {
	int val;
	struct node * next;
} node_t;

 node_t * head=NULL;
 node_t *currPtr = NULL;


 
 int lengthOfList(node_t **headPtr){
	 node_t *link = *headPtr;
	 int count=0;
	 while(link!=NULL){
		 count++;
		 link = link->next;
	 }
	 return count;
 }

void insertElement(int data, node_t **headPtr){
	node_t *link;
	
	link = malloc(sizeof(node_t));
	
	link->val = data;
	link->next = *headPtr;
	
	*headPtr = link;
}



void printList(node_t **headPtr){
	node_t *curr;
	
	curr=*headPtr;
	
	printf("\n List is : [");
	while(curr!=NULL){
		printf("%d,",curr->val);
		curr = curr->next;
	}
	printf("]");
}

//Return node of key.

node_t* returnNodePointer(int key,node_t **headPtr){
	
	node_t *link = *headPtr;
	
	while(link->val!=key&&link!=NULL){
		link = link->next;
	}
	
	return link;
	
}

int main(){

	node_t *head1 = NULL;
	node_t *head2 = NULL;
	node_t *LongList=NULL,*smallList;
	int len1 = 0;
	int len2 = 0;
	insertElement(10,&head1);
	insertElement(20,&head1);
	insertElement(30,&head1);
	insertElement(40,&head1);
	
	//now I want to insert in mid
	insertElement(50,&head2);
	insertElement(60,&head2);
	
	node_t *intersectLink = returnNodePointer(30,&head1);
	
	node_t *CurLinkHead2 = head2;
	
	while(CurLinkHead2->next!=NULL){
		CurLinkHead2 = CurLinkHead2->next;
	}
	
	CurLinkHead2 -> next = intersectLink;
	
	printList(&head1);
	printList(&head2);
	
	// now we know that list is overlapping.
	
	// 1. Find lengths.
	len1 = lengthOfList(&head1);
	len2 = lengthOfList(&head2);
	
	//2. Iterate on longer list.
	if(len1>len2){
		LongList = head1;
		smallList = head2;
		while((len1-len2)!=0){
			LongList=LongList->next;
			len1--;
		}
	}
	else {
		LongList = head2;
		smallList = head1;
		while((len2-len1)!=0){
			LongList=LongList->next;
			len2--;
		}
	}
	
	//3. Iterate till you find intersection.
	while(smallList->val!=LongList->val){
		smallList=smallList->next;
		LongList=LongList->next;
	}
	
	if(smallList==NULL||LongList==NULL){
		printf("No Intersection Found!");
	}
	else{
		printf("Inersection Found %d",smallList->val);
	}
	
	

return 0;
}
