class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        // Build the graph
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(source);
        vector<int> vis(n, 0);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            if(node == destination){
                return true;
            }
            for(auto it : graph[node]){
                if(vis[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return false;
    }
};