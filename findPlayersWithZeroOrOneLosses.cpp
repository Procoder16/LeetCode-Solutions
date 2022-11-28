class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map <int, int> loss_mp;
        vector<vector<int>> ans;
        
        for(int i = 0; i < matches.size(); i++){
            int win, loss;
            win = matches[i][0];
            loss = matches[i][1];
            loss_mp[loss] += 1;
        }
        
        vector<int> winner, loser;
        
        for(auto & mat: matches){
            int win, loss;
            win = mat[0];
            loss = mat[1];
            if(loss_mp.find(win) == loss_mp.end()){
                winner.push_back(win);  
            } 
            if(loss_mp.find(loss) != loss_mp.end() && loss_mp[loss] == 1){
                loser.push_back(loss);  
            } 
        }
        
        sort( winner.begin(), winner.end() );
        winner.erase( unique( winner.begin(), winner.end() ), winner.end() );
        
        sort( loser.begin(), loser.end() );
        loser.erase( unique( loser.begin(), loser.end() ), loser.end() );
        
        
        ans.push_back(winner);
        ans.push_back(loser);
        
     return ans;   
    }
};