/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *Node;
        TreeNode *Parent;
        TreeNode *z = (TreeNode *) malloc(sizeof(TreeNode));
        
        z->val = val;
        z->left = NULL;
        z->right = NULL;
        Node = root;
        Parent = NULL;
        
        while (Node != NULL) {
            
            Parent = Node;
            Node = (Node->val > val)?Node->left:Node->right;
        }
        
        if (root == NULL) {
            root = z;
        } else if (Parent->val < val) {
            Parent->right = z;
        } else {
            Parent->left = z;
        }
        
        return root;
    }
};