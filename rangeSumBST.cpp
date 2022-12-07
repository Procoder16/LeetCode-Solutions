class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        if(root -> val >= low && root -> val <= high){
            return rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high) + root -> val;
        }
        else{
            return rangeSumBST(root -> left, low, high) + rangeSumBST(root -> right, low, high);
        }
    }
};