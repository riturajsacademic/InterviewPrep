/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//
// Idea: For inorder the right is always greater than the key. 
//

class Solution {
public:

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* succ = NULL;
        
        while(root != NULL) {
            if (root->val > p->val) {
                succ = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        
        return succ;
    }
};