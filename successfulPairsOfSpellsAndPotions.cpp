class Solution {
public:
    int helper(int num,vector<int>& v,long long x){
        bool flag = false;
        int low = 0, high = v.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long prod = 1LL * num * v[mid];
            if(prod >= x){
                flag = true;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        if(!flag) 
            return -1;
        return low;
    }
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        int n = s.size();
        int m = p.size();
        vector<int> ans(n, 0);
        sort(p.begin(), p.end());
        for(int i = 0; i < n; i++){
            int ind = helper(s[i], p, success);
            if(ind != -1){
                ans[i] = (m - ind);
            }
        }
        return ans;
    }
};