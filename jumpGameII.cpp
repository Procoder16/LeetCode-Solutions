class Solution {
public:

    int jumpHelper(vector<int> &arr, int ind, int n){
        if(ind == n){
            return 0;
        }
        if(arr[ind] == 0){
            return -1;
        }
        
        int minJumps = 1e9;

        for(int i = 1; i <= arr[ind]; i++){
            if(ind + i <= n){
                int jumpRes = jumpHelper(arr, ind + i, n);
                if(jumpRes != -1){
                    minJumps = min(jumpRes + 1, minJumps);
                }
            }
        }
        return minJumps;
    }

    int jump(vector<int>& arr) {
        int n = arr.size();
        // return jumpHelper(arr, 0, n);
        vector<int> dp(n, 0);
        

        for(int i = n - 2; i >= 0; i--){
            int minJumps = 1e9;
            if(arr[i] == 0){
                dp[i] = -1;
            }else{
                for(int j = 1; j <= arr[i]; j++){
                    if(i + j < n){
                        int jumpRes = dp[i + j];
                        if(jumpRes != -1){
                            minJumps = min(jumpRes + 1, minJumps);
                        }
                    }
                }
            }
            
            dp[i] = minJumps;
        }
        return dp[0];
    }
};