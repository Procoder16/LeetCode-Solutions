class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int A = INT_MAX;
        int B = INT_MAX;
        
        for (auto &i: nums) {
            if (i < A) {
                A = i;
            } else if (i > A and i < B) {
                B = i;
            } else if (i > B) {
                return true;
            }
        }    
        return false;
    }
};