//First create the node for tree.


typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} node_t;

extern void printHello();
extern void insertNode(int key, node_t **link);
extern int searchNode(int key,node_t **link);
extern void printPreOrderNode(node_t *link);
extern void insertSortedArrayToBST(node_t **root,int arr[], int low, int high);
extern int maxDepth(node_t *node);
extern void insertList(node_t **root, int height);
extern void commanParentOfTwoNodes(int key1, int key2, node_t *link1,node_t *link2,node_t *parent);