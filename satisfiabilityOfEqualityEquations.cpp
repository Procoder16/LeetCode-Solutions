class Solution {
public:
    static bool cmp(string s1, string s2){
        return s1[1] != s2[1] && s1[1] == '=';
    }
    vector<int> par;
    Solution(){
        par.resize(26);
        iota(par.begin(), par.end(), 0);
    }
    
    int chint(char ch){
        return int(ch - 'a');
    }
    
    void Make(int ch){
        par[ch] = ch;
    }
    int Find(int ch){
        if(par[ch] == ch){
            return par[ch];
        }
        return par[ch] = Find(par[ch]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a != b){
            par[b] = a;
        }
    }
    
    bool equationsPossible(vector<string>& eq) {
        int n = eq.size();
        sort(eq.begin(), eq.end(), cmp);
        for(int i = 0; i < n; ++i){
            int a = chint(eq[i][0]);
            int b = chint(eq[i][3]);
            char op = eq[i][1];
            
            if(op == '='){
                Union(a, b);
            }else{
                if(Find(a) == Find(b)){
                    return false;
                }
            }
        }
        return true;
    }
};