class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int currSum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            int mod = currSum % k;
            if(mp.count(mod) > 0){
                if((i - mp[mod]) >= 2){
                    return true;
                }
            }else{
                mp[mod] = i;
            }
        }
        
        return false;
    }
};