class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         vector<vector<vector<int>>> dp(prices.size() + 1,
                                       vector<vector<int>>
                                       (2, vector<int>(k + 1)));
        
        for(int ind = prices.size() - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= k; cap++) {
                    if(buy == 0)
                        dp[ind][buy][cap] = max(dp[ind + 1][0][cap], -prices[ind] + dp[ind + 1][1][cap]);
                    else
                        dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][0][cap - 1], dp[ind + 1][1][cap]);
                }
            }
        }
        return dp[0][0][k];
    }
};
