class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            int currMin = q.front().second;
            int first, last;
            
            for(int i = 0; i < size; i++){
                long long currId = q.front().second - currMin;
                TreeNode* temp = q.front().first;
                q.pop();
                
                if(i == 0){
                    first = currId;
                }
                if(i == size - 1){
                    last = currId;
                }
                
                if(temp -> left){
                    q.push({temp -> left, 2 * currId + 1});
                }
                if(temp -> right){
                    q.push({temp -> right, 2 * currId + 2});
                }
            }
            
            ans = max(ans, last - first + 1);
        }
        
        return ans;
    }
    
};