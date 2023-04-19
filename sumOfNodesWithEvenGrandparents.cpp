class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int totalSum = 0;

        if(root == NULL){
            return totalSum;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto ele = q.front();
            TreeNode* currNode = ele.first;
            int level = ele.second;
            q.pop();

            if(level == 1){
                if(currNode -> left){
                    totalSum += currNode -> left -> val;
                }
                if(currNode -> right){
                    totalSum += currNode -> right -> val;
                }
            }
            if(currNode -> val % 2 == 0){
                if(currNode -> left){
                    q.push({currNode -> left, 1});
                }
                if(currNode -> right){
                    q.push({currNode -> right, 1});
                }
            }else{
                if(currNode -> left){
                    q.push({currNode -> left, 0});
                }
                if(currNode -> right){
                    q.push({currNode -> right, 0});
                }
            }
        }

        return totalSum;
    }
};