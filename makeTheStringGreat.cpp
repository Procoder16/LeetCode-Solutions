class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(auto c : s){
            if(c - '0' - 32 == ans.back() - '0' || c - '0' + 32 == ans.back() - '0'){
                ans.pop_back();
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};