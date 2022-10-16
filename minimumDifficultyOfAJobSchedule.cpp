class Solution{
public:
    vector<vector<int>> dp;
	
    int s(vector<int> &jobDifficulty, int d, int i){
        if (i == jobDifficulty.size()){
            return d == 0 ? 0 : 1e9;
        }

        if (d == 0){
            return 1e9;
        }

        if (dp[i][d] != -1){ 
            return dp[i][d];
        }

        int max1 = jobDifficulty[i];
        int ans = INT_MAX;

        for (int j = i; j < jobDifficulty.size(); j++){
            max1 = max(max1, jobDifficulty[j]);                    // updating the current Value
            ans = min(ans, max1 + s(jobDifficulty, d - 1, j + 1)); // Total (Ans = currentMax + leftItems)
        }
        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int> &j, int d){
        if (d > j.size()){
            return -1;
        }
        dp = vector<vector<int>>(j.size() + 5, vector<int>(12, -1));
        return s(j, d, 0);
    }
};