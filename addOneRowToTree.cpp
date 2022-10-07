TreeNode* addOneRow(TreeNode* root, int val, int depth,int curr=0) {
    
    if(depth==1){
        TreeNode* add=new TreeNode(val);
        if(curr==0){
            add->left=root;
        }
        else{
            add->right=root;
        }
        return add;
    }
    
    if(root==nullptr){
        return NULL;
    }
    root->left=addOneRow(root->left,val,depth-1,0);
    root->right=addOneRow(root->right,val,depth-1,1);
    return root;
}
