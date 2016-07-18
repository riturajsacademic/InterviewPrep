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

void deleteElementAtIndex(int index) {
	
	node_t *link = head;
	node_t *flink;
	
	if(index==0){
		head = link->next;
		free(link);
	}
	else {
		while(index>1){
			link = link->next;
			index--;
		}
		flink = link->next;
		
		link->next = flink->next;
		free(flink);
	}
	 
}

// Remove duplicates from linked list. 

//#1 Sorting Method

// #2 searching Method
void removeDuplicates_Searching(){
	node_t *llink,*ilink,*link,*delNode;
	
	ilink = head;
	
	while(ilink->next!=NULL){
		
		// initializing links - should always start from here.
		llink=ilink;
		link=llink->next;
		
		while(link!=NULL){
			if(link->val==ilink->val){
				// removing key.
				delNode = link;
				link = link->next;
				llink->next = link;
				free(delNode);
			}
			else if(link!=NULL){
				llink=link;
				link=link->next;
			}
		}
		if(ilink->next!=NULL)
			ilink= ilink->next;
	}
}

//#3 using a hashMap. -- how to make a hashmap in c??

//-------

// Removing Kth from the last element. 
void removeKthFromLast(int index){
	
	node_t *link = head;
	node_t *dlink=NULL;
	
	if(index>lengthOfList()||index<1)
	{
		return;
	}
	
	index = lengthOfList()-index;
	while(index!=1){
		link = link->next;
		index--;
	}
	
	dlink = link->next;
	
	link->next = dlink->next;
	
	free(dlink);

}


int main(){

int choice,element,index;

choice = 0;
while(choice){
	printf("\nWhat would you like to do? ");
	printf("\n1. Insert.");
	printf("\n2. delete");
	printf("\n3. print");
	printf("\n4. search");
	printf("\n5. delete at index");
	printf("\n6. delete key");
	printf("\n0. Exit.");

	scanf("%d",&choice);
	switch(choice){
		case 1:	printf("Enter Element: ");
			scanf("%d",&element);
			insertElement(element);
			break;
		case 2:	printf("Delete Element: ");
			deleteFirst();
			break;
		case 3: printList();
			break;
		case 4:
			printf("Enter Element: ");
			scanf("%d",&element);
			index = searchForIndex(element);
			if(index == lengthOfList()){
				printf("\nElement not found");
			}
			else 
				printf("%d",index);
			break;
		case 5: printf("Enter Element: ");
			scanf("%d",&element);
			deleteElementAtIndex(element);
		case 6: printf("Enter Element: ");
			scanf("%d",&element);
			deleteElement(element);
		case 0: break;
	}
}	
	/// Test Case 1. removing duplicates from searching.
	if(0) {
		insertElement(4);
		insertElement(4);
		insertElement(2);
		insertElement(2);
		insertElement(2);
		printList();
		removeDuplicates_Searching();
		printList();
	}
	// test case 2. For removing kth from the last element.
	
	if(1) {
		insertElement(10);
		insertElement(20);
		insertElement(30);
		insertElement(40);
		insertElement(50);
		printList();
		removeKthFromLast(-1);
		printList();
	}

return 0;
}
