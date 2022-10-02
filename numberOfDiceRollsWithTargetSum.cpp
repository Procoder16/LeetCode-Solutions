class Solution {
public:
long long solve(int n, int k , int target, vector<vector<int>>&dp){
    
    if(target == 0 && n == 0)
        return 1;
        if(n == 0 && target > 0)
        return 0;
        if(dp[n][target] != -1) return dp[n][target];
        long long  ans = 0;
        for(int i = 1 ; i <= k ; i++){
           if(target >= i) {
               ans+= solve(n-1, k,target-i,dp) % 1000000007;
           }
           else break;
        }
        return dp[n][target] = ans % 1000000007;
}
    int numRollsToTarget(int n, int k, int target) {
          vector<vector<int>> dp(31 , vector<int> (1001, -1));
       return solve(n,k,target,dp);
    
    }
};