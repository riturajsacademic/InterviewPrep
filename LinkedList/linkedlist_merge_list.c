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
	while(curr->next!=NULL){
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



void mergeList(node_t **head1, node_t ** head2, node_t **head3) {
	// declaring temp variables.
	node_t *curr1 = *head1;
	node_t *curr2 = *head2;
	node_t *curr3 = NULL;
	

	while(curr1!=NULL && curr2!=NULL){
		
		if(curr1->val<curr2->val){
			
			if (curr3==NULL){
				curr3=curr1;
			}
			else {
				curr3->next = curr1;
			}
			curr1=curr1->next;
		}
		else {
			if (curr3==NULL){
				curr3=curr1;
			}
			else {
				curr3->next = curr2;
			}
			
			curr2 = curr2->next;
		} 
		
		if(head3==NULL){
			*head3 = curr3;
		}
		
		if(curr3!=*head1||curr3!=*head2)
			curr3 = curr3->next;	
		
	}
	
	if(curr1==NULL){
		curr3->next = curr2;
	}
	else {
		curr3->next = curr1;
	}
		
}


int main(){

	node_t *head1;
	node_t *head2;
	node_t *head3;
	
	insertElement(5,&head1);
	insertElement(3,&head1);
	insertElement(1,&head1);
	//printList(&head1);
	
	insertElement(6,&head2);
	insertElement(4,&head2);
	insertElement(2,&head2);
	printList(&head2);

	
	//mergeList(&head1,&head2,&head3);
	//printList(&head3);
	
return 0;
}
