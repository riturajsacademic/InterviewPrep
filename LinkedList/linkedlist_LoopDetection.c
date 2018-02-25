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

void detectLoop(node_t **headPtr){
	
	node_t *slow = *headPtr;
	node_t *fast = *headPtr;
	
	while(fast!=NULL){
		fast=fast->next;
		if(fast->next!=NULL){
			slow = slow->next;
			fast = fast->next;
		}
		if(slow==fast)
			break;
	}
	
	//check if there is no loop.
	if(fast==NULL){
		printf("\nNo loop.");
	}
	
	if(slow==fast){
		fast = *headPtr;
		while(slow!=fast){
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	printf("Intersection at : %d",slow->val);
	
	
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
	insertElement(50,&head1);
	insertElement(60,&head1);
	insertElement(70,&head1);
	insertElement(80,&head1);
	// Wont work. As list is circular. It would never reach null. if it was then it would return null.
	node_t *intersectLink = returnNodePointer(0,&head1);
	
	// find tail pointer and point it to intersect link. 
	
	node_t *endTail = returnNodePointer(10,&head1);
	
	endTail->next = intersectLink;
	
	//Circular list is formed.
	//printList(&head1);
	
	detectLoop(&head1);
	return 0;
}
