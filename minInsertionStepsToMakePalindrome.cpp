class Solution {
public:

    int lps(string str1, string str2){
        int len = str1.length();

        //vector<vector<int>> dp(len + 1, vector<int> (len + 1, 0));
        vector<int> prev(len + 1, 0);
        vector<int> curr(len + 1, 0);

        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= len; j++){
                if(str1[i - 1] == str2[j - 1]){
                    curr[j] = 1 + prev[j-1];
                }else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[len];
    }

    int minInsertions(string s) {
        string t = s;
        int len = s.length();
        reverse(t.begin(), t.end());

        int lpsLen = lps(s, t);

        return len - lpsLen;
    }
};