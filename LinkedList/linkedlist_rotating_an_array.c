#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node 
{
    int val;
    struct node* next;
} node_t ;

node_t *head=NULL;

void printList(){
	node_t *curr;
	
	curr=head;
	
	printf("\n List is : [");
	do{
		printf("%d,",curr->val);
		curr = curr->next;
	}while(curr!=head);
	printf("]");
}

void insertElement(int data){
	node_t *link;
	node_t *currPtr;
	link = malloc(sizeof(node_t));
	printf("In");
	link->val = data;
	link->next = head;
    
     
	if(head==NULL){
	   head = link;
	   link->next = head;
    }
    else{
        //find the last element and then insert this.
        currPtr=head;
        while(currPtr->next!=head){
            currPtr = currPtr->next;
        }
        currPtr->next = link;
    }
	//printList();
}
int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int a;
	int a_i;
    for(a_i = 0; a_i < n; a_i++){
       scanf("%d",&a);
       insertElement(a);
    }
    printList();
   
    return 0;
}
