class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0;
        int j=n-1;
        while(i<j){
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            
            else if(power+tokens[j]>=tokens[i] && score>=1){
                power+=tokens[j];
                score--;
                j--;
            }
            else
                break;  
        }
        
        while(i<j+1 && power>=tokens[i]){
            score++;
            power-=tokens[i];
            i++;
        }
        return score;
    }
};