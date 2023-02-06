class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> a;
        vector<int> b;
        
        for(int i=0; i<n; i++){
            a.push_back(nums[i]);
        }
        
        for(int i=n; i<2*n; i++){
            b.push_back(nums[i]);
        }
        
        vector<int> newV;
        
        for(int i=0; i<n; i++){
            newV.push_back(a[i]);
            newV.push_back(b[i]);
        }
        
        return newV;
    }
};