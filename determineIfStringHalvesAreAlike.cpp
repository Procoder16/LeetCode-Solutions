class Solution {
public:
    bool halvesAreAlike(string s) {
        int len = s.length();
        int countA = 0;
        int countB = 0;
        
        for(int i = 0; i< len/2; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                countA++;
            }
        }
        
        for(int i = len/2 ; i < len; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                countB++;
            }
        }
        
        if(countA == countB){
            return true;
        }
        else{
            return false;
        }
    }
};