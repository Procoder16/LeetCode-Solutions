class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for(auto n : arr){
            m[n]++;
        }
        
        for(auto t : m){
            s.insert(t.second);
        }
        
        if(m.size() == s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};