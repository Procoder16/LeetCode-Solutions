/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(int sum, int target, vector< int >&path, 
                 TreeNode* root, vector< vector< int > >&paths) {
        
        if(root == NULL) 
            return;

        path.push_back(root->val);
        sum += root->val;
        
        if(root->left == NULL && root->right == NULL) {
            if(target == sum) 
                paths.push_back(path);
        }
        
        inorder(sum, target, path, root->left, paths);
        inorder(sum, target, path, root->right, paths);
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector< int >path;
        vector< vector< int > >paths;
        
        inorder(0, targetSum, path, root, paths);
        
        return paths;
    }
};