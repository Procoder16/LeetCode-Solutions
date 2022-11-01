class Solution {
private:
    int canBallReachBottom(int i, vector<vector<int>>& grid){
        int row = 0, column = i;
        while(row != grid.size()){
            if(grid[row][column] == 1){
                if(column == grid[0].size()-1 || grid[row][column+1] == -1)
                    return -1;
                row++;
                column++;
            }
            else{
                if(column == 0 || grid[row][column-1] == 1)
                    return -1;
                row++;
                column--;
            }
        }
        return column;
    }
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> answer(grid[0].size());
        
        for(int i = 0; i < grid[0].size(); i++){
            answer[i] = canBallReachBottom(i, grid);
        }
        return answer;
    }
};