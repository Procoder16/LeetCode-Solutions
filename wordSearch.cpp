class Solution {
public:
    int m, n, l;
    
    bool find(vector<vector<char>>& board, string& word, vector<vector<bool>>&visited, int i, int j, int p)
    {
	// if index of word out of bound means word found
        if(p >= l)
                return true;
				
        if(i < m and i >= 0 and j < n and j >= 0 and board[i][j] == word[p] and !visited[i][j])
        {
            visited[i][j] = true;
            
            bool f1 = find(board, word, visited, i+1, j, p+1);
            bool f2 = find(board, word, visited, i-1, j, p+1);
            bool f3 = find(board, word, visited, i, j+1, p+1);
            bool f4 = find(board, word, visited, i, j-1, p+1);
            
            visited[i][j] = false;
            
            return f1 or f2 or f3 or f4;
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();
        l = word.length();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(find(board, word, visited, i, j, 0))
                    return true;
            }
        }
        
        return false;
    }
};