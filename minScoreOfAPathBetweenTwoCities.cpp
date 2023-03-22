class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        int len = roads.size();
        vector<vector<pair<int,int>>>graph(n+1);
        
        for(int i = 0; i < len; i++){
            pair a = {roads[i][1], roads[i][2]};
            pair b = {roads[i][0], roads[i][2]};
            graph[roads[i][0]].push_back(a);
            graph[roads[i][1]].push_back(b);
        }
        
        vector<int> vis(n+2, 0);
        
        queue<vector<int>> q;
        
        q.push({n, 10001});
        
        int minLength = 10001;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            minLength = min(minLength, node[1]);
            vis[node[0]] = 1; 
            for(auto it : graph[node[0]]){
                if(!vis[it.first]){
                    q.push({it.first, it.second});
                }
            }
        }
        return minLength;
    }
};