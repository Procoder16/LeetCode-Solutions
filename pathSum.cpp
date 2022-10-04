class Solution {
public:
    void f(vector<int> &v,TreeNode * root , int &sum){
        if(root->left == NULL && root->right == NULL){
            sum+=(root->val);
            v.push_back(sum);
            sum-=(root->val);
            return ;
        }
        sum+=(root->val);
        if(root->left != NULL){
        f(v,root->left,sum);
        }
        if(root->right != NULL){
        f(v,root->right,sum);
        }
        sum-=(root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false;
        }
        vector<int> v;
        int s = 0;
        f(v,root,s);
        auto it = find(v.begin(),v.end(),targetSum);
        if(it == v.end()){
            return false;
        }
        return true;
    }
};
