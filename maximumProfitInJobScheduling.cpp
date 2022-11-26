class Solution {
private:
    struct interval
    {
        int st;
        int en;
        int profit;
    };
    
    vector<interval> nums;
    vector<int> dp;

    int getLowerBound(int idx)
    {
        int low = idx+1;
        int high = size(nums)-1;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid].st >= nums[idx].en)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
    int getMaxProfit(int idx = 0)
    {
        if(idx>=size(nums))
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int nextElementIdx = getLowerBound(idx);
        int include = nums[idx].profit + (nextElementIdx==-1 ? 0 : getMaxProfit(nextElementIdx));
        int exclude = getMaxProfit(idx+1);
        return dp[idx] = max(exclude,include);
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = size(startTime);
        nums.resize(n);
        dp.resize(n+1,-1);
        for(int i=0;i<n;i++)
        {
            nums[i].st = startTime[i];
            nums[i].en = endTime[i];
            nums[i].profit = profit[i];
        }
        sort(nums.begin(),nums.end(),[&](struct interval a,struct interval b){
            return a.st < b.st;
        });
        return getMaxProfit();
    }
};