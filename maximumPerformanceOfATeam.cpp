class Solution {
public:
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            v.push_back({e[i],s[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>,greater<int>>min_heap;
        long int a = 0;
        long int p = pow(10,9) + 7;
        long int ans = 0;
        for(int i=n-1;i>-1;i--){
            min_heap.push(v[i][1]);
            a += v[i][1];
            if(min_heap.size()>k){
                a -= min_heap.top();
                min_heap.pop();
            }
            ans = max(ans,a*v[i][0]);
        }
        ans = ans%p;
        return ans;
    }
};