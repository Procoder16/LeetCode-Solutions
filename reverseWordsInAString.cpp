class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        reverse(s.begin(),s.end());
        
        int i = 0, j = 0;
        
        while(i < s.length() && j < s.length()){
            // i pointer will move-forware while there is a white space
            while(s[i] == ' ' && i < s.length()){
                i++;
            }
            j = i;
            
            // j pointer will move-forware while there is no white space
            while(s[j] != ' ' && j < s.length()){
                j++;
            } 
            
            string word = s.substr(i,j-i);
            i = j+1;
            reverse(word.begin(),word.end());
            
            res += word;
            res += " ";
        }
        
        int n = res.length()-1;
        while(res[n] == ' '){
            res.pop_back();
            n--;
        }
        
        return res;
    }
};