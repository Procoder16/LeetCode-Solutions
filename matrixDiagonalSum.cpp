class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        
        int k = (mat[0].size()) - 1;
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if((i == j) || i + j == k){
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};