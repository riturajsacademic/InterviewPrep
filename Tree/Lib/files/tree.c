#include "..\tree_structure.h"
#include <stdio.h>
#include <stdlib.h>

void insertList(node_t **root, int height) {
	node_t *curr = *root;
	if(height==0 && curr!=NULL){
		printf("\n Inserting: %d",curr->key);
	}
	else {
		height-=1;
		insertList(&(curr->left),height);
		insertList(&(curr->right),height);
	}
}

int maxDepth(node_t *node){
	if(node==NULL){
		return 0;
	}
	else {
		int leftMax = maxDepth(node->left);
		int rightMax = maxDepth(node->right);
		
		// Added information for balanced or not. 
		
		int diff = abs(rightMax-leftMax);
		if(diff>1){
			printf("Unbalanced.");
		}
		
		return (leftMax>rightMax)?(leftMax+1):(rightMax+1);
	}
}
void insertSortedArrayToBST(node_t **root,int arr[], int low, int high) {
	
	if(low>high){
		return;
	}
	else {
			
		int mid = (low+high)/2;
		insertNode(arr[mid],&(*root));
		
		insertSortedArrayToBST(&(*root),arr,low,mid-1);
		insertSortedArrayToBST(&(*root),arr,mid+1,high);
	}
	
}


void printHello()
{
	printf("This world");
}

void insertNode(int key, node_t **link){
	
		node_t *curr=NULL;
		node_t *tempnode;
		node_t *parent = *link;
		tempnode = malloc(sizeof(node_t));
		tempnode->key = key;
		tempnode->left = tempnode->right = NULL;
		
		if(	parent==NULL){
			*link = tempnode;
			
			return;
		}
		else {
			curr = parent;
			while(1){
				parent=curr;
				
				if(key<curr->key){
					curr = curr->left;
					if(curr==NULL){
						parent->left = tempnode;
						return;
					}
				}
				else if(key>curr->key){
					curr = curr->right;
					if(curr==NULL){
						parent->right = tempnode;
						return;
					}
				}
				
			}
		}
	
}

// make sure both nodes are in tree.
// if both keys are the same then just find the pointer to the root.
void commanParentOfTwoNodes(int key1, int key2, node_t *link1,node_t *link2,node_t *parent){
	
	if(link1!=link2){
		//
		//	Base Case
		//
		
		printf("Parent is: %d",parent->key);
	}
	else if(link1==link2){
		parent = link1;
		
		commanParentOfTwoNodes(key1,
							    key2,
								(link1->key<key1)?link1->right:link1->left,
								(link2->key<key2)?link2->right:link2->left,
								parent);
	}
	
}


int searchNode(int key,node_t **link){
	node_t *curr = *link;
	
	if(curr->key==key){
		return key;
	}
	while(curr->key!=key){
		
		if(curr->key<key){
			curr = curr->right;
		}
		else{
			curr=curr->left;
		}
		
		if(curr==NULL){
			return 0;
		}		
	}
	return curr->key;
}

void printPreOrderNode(node_t *link){
	if(link!=NULL){
		printf("%d , ",link->key);
		printPreOrderNode(link->left);
		printPreOrderNode(link->right);
	}
}

