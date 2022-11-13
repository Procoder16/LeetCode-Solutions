class Solution {
public:
    string removeDuplicates(string s) {
        string res = "";
        for(char c : s){
            if(res.back() != c){
                res.push_back(c);
            }
            else{
                res.pop_back();
            }
        }
        return res;
    }
};