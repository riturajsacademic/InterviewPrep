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
	printList(*head1);
	
	insertElement(6,&head2);
	insertElement(4,&head2);
	insertElement(2,&head2);
	printList(*head2);

	
	mergeList(&head1,&head2,&head3);
	printList(*head3);
	
return 0;
}
