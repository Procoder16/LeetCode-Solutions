#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
            //unique will remove the duplicate elements and then make the unique elements contiguous
            // then it would return the pointer to the last position uptil where the elements are there
            //erase will remove the empty space at the end
	    int n = 0;
	    for(int i = 1; i < nums.size() -1; ++i)
		    n += (nums[i - 1] > nums[i]) == (nums[i] < nums[i + 1]); 
        return n;
    }
};