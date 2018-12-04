/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//
// Idea: Use a stack to find the next element.
//     1. insert all the left sub-elements of a tree. 
//     2. 
// 
//
class BSTIterator {
public:
    vector<TreeNode *> stack;
    
    void push (TreeNode *node) {

        stack.insert(stack.begin(),node);
    }
    
    TreeNode * pop () {
        TreeNode *toret;
        
        toret = stack.front();
        stack.erase(stack.begin());

        return toret;
    }
    
    BSTIterator(TreeNode *root) {
        
        while (root != NULL) {
            push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        return !stack.empty();
    }

    /** @return the next smallest number */
    int next() {

        TreeNode * toret = pop();
        int val = 0;
        
        val = toret->val;
        toret = toret->right;
        while (toret != NULL) {
           push(toret);
           toret = toret->left;
        }
        
        return val;        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */