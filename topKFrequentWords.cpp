class Solution {
public:
    static bool  comp( pair<string,int> p1, pair<string,int> p2) {
        if (p1.second == p2.second) {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<string,int>> v;
        vector<string> ans;
        map<string,int> mp;
        int n = words.size();
        for (int i = 0; i < n;i++) {
            mp[words[i]]++;
        }
        for (auto i : mp) {
            v.push_back(make_pair(i.first,i.second));
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < k;i++) {
            ans.push_back(v[i].first);
        } 
        
        return ans;
    }
};