#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define lli long long int

class Solution {
public:
lli lcm(lli a, lli b){
    return a*(b/__gcd(a, b));
}
long long int Count(vector<int>nums, long long int k) {
    lli res = 0;
    int len = nums.size();
    int i, j;
    for(i = 0; i < (1 << len); i++){
        lli temp = 1;
        int c = 0;
        for(j = 0; j < len; j++){
            if(i & (1 << j)){
                c++;
                if(temp <= k){
                    temp = lcm(temp, nums[j]);
                }
            }
        }
        if(!c)continue;
        if(c&1)
        res += (k/temp);
        else
        res -=(k/temp);
    }
    return res;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long int k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n;i++)
			cin >> nums[i];
		Solution obj;
		long long int ans = obj.Count(nums, k);
		cout << ans << "\n";
	}
	return 0;
}