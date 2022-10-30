class Solution {
public:
    int bfs(vector<vector<int>>& grid,int k)
    {
        queue<vector<int>> q;
        
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<vector<int>>> visited(n,vector<vector<int>>(m,vector<int>(k+1)));
        
        q.push({0,0,k});
        visited[0][0][k] = 1;
        
        int prev = 1;
        int ans = 0;
        
        
        while(!q.empty())
        {
            int count = 0;
            while(prev--)
            {
                int i = q.front()[0];
                int j = q.front()[1];
                int k = q.front()[2];
                
                q.pop();
                 if(k<0)
                    continue;
                
                if(i==n-1 && j==m-1)
                    return ans;
                
                int k1 = k;
                
                if(i>0 && k-grid[i-1][j]>=0 && !visited[i-1][j][k-grid[i-1][j]])
                {
                    q.push({i-1,j,k-grid[i-1][j]});
                    visited[i-1][j][k-grid[i-1][j]] = 1;
                    count++;
                }
                if(i<n-1 && k-grid[i+1][j]>=0 && !visited[i+1][j][k-grid[i+1][j]])
                {
                    q.push({i+1,j,k-grid[i+1][j]});
                    visited[i+1][j][grid[i+1][j]] = 1;
                    count++;
                }
                if(j>0 && k-grid[i][j-1]>=0 && !visited[i][j-1][k-grid[i][j-1]])
                {
                    q.push({i,j-1,k-grid[i][j-1]});
                    visited[i][j-1][k-grid[i][j-1]] = 1;
                    count++;
                }
                if(j<m-1 && k-grid[i][j+1]>=0 && !visited[i][j+1][k-grid[i][j+1]])
                {
                    q.push({i,j+1,k-grid[i][j+1]});
                    visited[i][j+1][k-grid[i][j+1]] = 1;
                    count++;
                }
            }
            prev = count;
            ans++;
        }
        return -1;
    }
    
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        return bfs(grid,k);
        
    }
};