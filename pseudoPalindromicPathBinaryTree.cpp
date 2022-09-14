class Solution {
    int count;
public:
    void helper(TreeNode* root,vector<int> &freq){
        
        if(root==NULL)
            return;
        
        freq[root->val]++; 
        
        helper(root->left,freq);
        helper(root->right,freq);
        
        if(root->left==NULL && root->right==NULL){
            
            int odd_count=0; 
            
            for(int it=1;it<=9;it++){
                if(freq[it]%2)
                    odd_count++;
            }
            
            if(odd_count<=1) 
                count++;
        }
        
        freq[root->val]--; 
        
    }
    int pseudoPalindromicPaths (TreeNode* root){
        
        if(root==NULL)
            return 0;
        
        vector<int> freq(10,0); 
                        
        helper(root,freq);
        
        return count;
    }
};