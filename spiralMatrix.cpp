class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        if(m==1 && n==1){
            ans.push_back(matrix[0][0]);
            return ans;
        }
        int dir = 1;

        int left=0 , right=n-1 , up=0 , down=m-1;
        while(left <= right && up <= down){
                if(dir == 1){
                    for(int i=left;i<=right;i++)
                        ans.push_back(matrix[up][i]);
                    up++;
                    dir++;
                }
                else if(dir == 2){
                    for(int i=up;i<=down;i++)
                        ans.push_back(matrix[i][right]);
                    right--;
                    dir++;
                }
                else if(dir == 3){
                    for(int i=right;i>=left;i--)
                        ans.push_back(matrix[down][i]);
                    down--;
                    dir++;
                }
                else{
                    for(int i=down;i>=up;i--)
                        ans.push_back(matrix[i][left]);
                    left++;
                    dir = 1;
                }
            
        }
        return ans;
    }
};