class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int len = nums.size();
        long long countSubarray = 0;
        int currCount = 0;

        for(int i = 0; i < len; i++){
            if(nums[i] == 0){
                currCount++;
                countSubarray += currCount;
            }else{
                currCount = 0;
            }
        }

        return countSubarray;
    }
};