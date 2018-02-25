#include <stdio.h>
#include <stdlib.h>
/*
Question: Find if a list is palindrome.

1. Reverse Index.
	Calculates the mid index for the list.

2. Reverse the list 

Ex 
1->2->4->2->1 TO 4->2->1->2->1-

3. Compare the elements and see if they are palindrome or not. 

4. Reverse the list back.

*/
typedef struct node {
	int val;
	struct node * next;
} node_t;

 node_t * head=NULL;
 node_t *currPtr = NULL;


 
 int lengthOfList(node_t *headPtr){
	 node_t *link = headPtr;
	 headPtr = NULL;
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

//return index. 

int returnIndex(node_t *headPtr){
	int len = lengthOfList(headPtr);
	int result = (len%2==0) ? (len/2):(len/2+1);
	return result;
}

//ReverseList. 
void ReverseList(node_t **headPtr,int mid){
	node_t *prev = *headPtr;
	node_t *curr = prev->next;
	node_t *forward = curr->next;
	node_t *betNode;
	
	while(mid!=1){
		curr->next=prev;
		prev=curr;
		curr=forward;
		forward=forward->next;
		mid--;
	}
	betNode = *headPtr;
	betNode->next = curr;
	
	*headPtr = prev;
}

void checkPalindrome(node_t **headPtr,int mid){
	node_t *link=NULL;
	node_t *slowPtr,*fastPtr;
	
	ReverseList(headPtr,mid);
	
	//Comparing.
	//
	link = *headPtr;
	slowPtr = fastPtr = link;
	
	//push a link forward.
	if(lengthOfList(*headPtr)%2!=0){
		link=link->next;
	}
	
	while(fastPtr!=NULL){
		fastPtr = fastPtr->next;
		if(fastPtr!=NULL&&fastPtr->next!=NULL){
			fastPtr=fastPtr->next;
			slowPtr=slowPtr->next;
		}
		
	}
	
	slowPtr = slowPtr->next;
	
	while(slowPtr!=NULL){
		if(slowPtr->val!=link->val){
			printf("Not a Palindrome");
			break;
		}
		slowPtr=slowPtr->next;
		link=link->next;
	}
	if(slowPtr==NULL){
		printf("Palindrome");
	}
	
	
	
	//reversing it back.
	ReverseList(headPtr,mid);
	
}

int main(){

	node_t *head1 = NULL;
		
	int len1 = 0;
	int len2 = 0;
	//insertElement(1,&head1);
	insertElement(2,&head1);
	insertElement(4,&head1);
	insertElement(2,&head1);
	insertElement(1,&head1);

	int mid = returnIndex(head1);
	
	checkPalindrome(&head1,mid);
	
	
	
	return 0;
}
