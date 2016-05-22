#include <stdio.h>

typedef struct node {
	int val;
	struct node * next;
} node_t;

int insertElement(


int main(){

int choice,element;

node_t * head=NULL,curr;
curr = head;

printf("What would you like to do? ");
printf("\n1. Insert in linked list.");
printf("\n2. delete linked list.");
printf("\n3. print linked list.");

scanf("%d",&choice);
switch(choice){
	case 1:	printf("Enter Element: ");
		scanf("%d",&element);
		insertElement(element,curr);
	case 2:	printf("Delete Element: ");
		scanf("%d",&element);
	case 3: printList();
}

return 0;
}
