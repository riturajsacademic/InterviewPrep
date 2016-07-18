#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

 node_t * head=NULL;
 node_t *currPtr = NULL;

int searchForIndex(int data){
	node_t *link = head;
	int index = -1;
	
	while(link!=NULL&&link->val!=data){
		index++;
		link=link->next;
	}
	
	return index+1;
}
 
 int lengthOfList(){
	 node_t *link = head;
	 int count=0;
	 while(link!=NULL){
		 count++;
		 link = link->next;
	 }
	 return count;
 }

void insertElement(int data){
	node_t *link;
	
	link = malloc(sizeof(node_t));
	
	link->val = data;
	link->next = head;
	
	head = link;
}

void deleteFirst(){
	
	node_t *link = head;
	
	head = link->next;
	
	free(link);
	//printList();
}

void printList(){
	node_t *curr;
	
	curr=head;
	
	printf("\n List is : [");
	while(curr!=NULL){
		printf("%d,",curr->val);
		curr = curr->next;
	}
	printf("]");
}

void deleteElement(int key){
	node_t *llink = head;
	node_t *link = head;
	node_t *midLink;
	
	if(head->val== key){
		head = link->next;
		free(link);
	}
	else{
		link = link->next;
		while(link!=NULL){
			if(link->val==key){
				midLink = link->next;
				llink->next = midLink;
				free(link);
				break;		// need to break here, as we delete link and while still uses link.
			}
			else{
				llink=link;
				link = link->next;
			}
		}
	}
}

/*
	Function List: 
	Insertfirst
	deleteFirst
	deleteElement with the key.
	lengthOfList
	printList
	searchForIndex : Returns index of a key.
*/

int main(){

return 0;
}
