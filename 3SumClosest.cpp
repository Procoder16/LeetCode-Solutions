int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int ansSum = 0;
        int minDiff = INT_MAX;
        for(int i = 0; i < len - 2; i++){
            int j = i + 1;
            int k = len - 1;
            while(j < k){
                int tempSum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - tempSum);
                if(diff < minDiff){
                    ansSum = tempSum;
                    minDiff = diff;
                }
                if(tempSum == target){
                    return ansSum;
                }
                else if(tempSum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ansSum;
    }