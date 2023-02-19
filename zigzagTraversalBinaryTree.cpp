class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root == NULL){
            return {};
        }

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> temp;
        int flag = 0;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node != NULL){
                int data = node -> val;
                temp.push_back(data);
                if(node -> left != NULL){
                    q.push(node -> left);
                }
                if(node -> right != NULL){
                    q.push(node -> right);
                }
            }else{
                if(flag == 0){
                    ans.push_back(temp);
                    flag = 1;
                }else{
                    reverse(temp.begin(), temp.end());
                    ans.push_back(temp);
                    flag = 0;
                }
                temp.clear();
                if(!q.empty()){
                    q.push(NULL);
                }                
            }
        }

        return ans;
    }
};