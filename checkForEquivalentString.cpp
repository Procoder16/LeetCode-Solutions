class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        
        string ans1 = "";
        string ans2 = "";
        
        for(int i = 0; i<size1; i++){
            ans1 += word1[i];
        }
        
        for(int i = 0; i<size2; i++){
            ans2 += word2[i];
        }
        
        if(ans1 == ans2){
            return true;
        }
        
        else{
            return false;
        }
        
    }
};