int p[100005];

int Find(int x){
    if(p[x] == x) 
        return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b){
    p[Find(b)] = Find(a);
}

class Solution {
public:
    bool static compare(vector<int>&a, vector<int>&b){
        return a[2] < b[2];
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
        int qs = queries.size();
        vector<bool> ans(qs);
        vector<vector<int>> que(qs);
        for(int i = 0; i < qs; i++){
            que[i] = queries[i];
            que[i].push_back(i);
        }
        sort(edgeList.begin(), edgeList.end(), compare);
        sort(que.begin(), que.end(), compare);
        int k = 0;
        for(auto &qu: que){
            int p = qu[0];
            int q = qu[1];
            int limit = qu[2];
            int ind = qu[3];
            while(k < edgeList.size() && edgeList[k][2] < limit){
                int u = edgeList[k][0];
                int v = edgeList[k][1];
                Union(u, v);
                k += 1;
            }
            ans[ind] = (Find(p) == Find(q));
        }
        return ans;
    }
};