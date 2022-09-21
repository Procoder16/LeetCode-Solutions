class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            if((it%2)==0){
                sum+=it;
            }
        }
        vector<int> ans;
        for(auto it:q){
            int i=it[1], x=it[0];
            if((abs(nums[i])%2)==0){
                sum-=nums[i];
            }
            if((nums[i]+x)%2==0)sum+=(nums[i]+x);
            nums[i]+=x;
            ans.push_back(sum);
        }
        return ans;
    }
};