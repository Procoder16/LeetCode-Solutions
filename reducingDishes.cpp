class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        int maxVal = 0;
        int currVal = 0;

        for(int i = 0; i < satisfaction.size(); i++){
            currVal += satisfaction[i];
            if(currVal < 0){
                return maxVal;
            }
            maxVal += currVal;
        }

        return maxVal;
    }
};