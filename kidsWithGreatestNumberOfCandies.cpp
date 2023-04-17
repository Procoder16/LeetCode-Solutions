class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = 0;
        for(int i = 0; i<candies.size();i++){
            maxC = max(maxC, candies[i]);
        }
        
        vector<bool> a;
        
        for(int i = 0; i<candies.size();i++){
            if(candies[i]+ extraCandies>=maxC){
                a.push_back(true);
            }
            else{
                a.push_back(false);
            }
        }
        
        return a;
    }
};