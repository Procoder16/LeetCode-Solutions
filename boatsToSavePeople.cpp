#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int countOfBoats = 0;
        
        sort(people.begin(), people.end());
        
        int low = 0, high = people.size() - 1;
        
        while(low <= high){
            countOfBoats++;
            if(people[low] + people[high] <= limit){
                low++;
            }
            high--;
        }
        return countOfBoats;
    }
};