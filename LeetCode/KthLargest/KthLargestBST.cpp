class KthLargest {
public:

    int Largest;
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        int count;
        //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    
    TreeNode *Master;
    int kth;
    
    void printInorder (TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        printInorder(root->left);
        printf("(%d:%d)",root->val,root->count);
        printInorder(root->right);
        return;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode * ToRet;
        //
        // Base Case.
        //
        
        if (root == NULL) {
            ToRet = (TreeNode *) malloc(sizeof(TreeNode));
            ToRet->val = val;
            ToRet->left = NULL;
            ToRet->right = NULL;
            ToRet->count = 1;
            return ToRet;
        } else if (root->val >= val) {
            root->left = insertIntoBST(root->left,val); 
        } else if (root->val < val){
            root->right = insertIntoBST(root->right,val);
        }
        
        //
        // increment everytime.
        //
        
        root->count++;
        return root;
    }
    
    int findKth(TreeNode * root, int k) {
        
        if (root == NULL) {
            return 0;
        }
        
        int rc = (root->right)?root->right->count:0;
        
        if (k == rc+1) {
            return root->val;
        } else if (k-1 < rc) {
            return findKth(root->right,k);
        } else if (k-1 > rc) {
            return findKth(root->left,k - rc - 1); // here 1 is for the root element. Find K-rc-1st element in the subtree.
        }
    }
    
    KthLargest(int k, vector<int> nums) {
        int index;
        Master = NULL;
        for(index = 0; index < nums.size(); index++) {
            Master = insertIntoBST(Master,nums[index]);
        }
        kth = k;
    }
    
    int add(int val) {
        Master = insertIntoBST(Master,val);
        return findKth(Master, kth);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */