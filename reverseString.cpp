#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<char> reverseString(vector<char>& s) {
        int first = 0;
        int last = s.size() - 1;
        while(first<=last){
            char c = s[first];
            s[first] = s[last];
            s[last] = c;
            first++;
            last--;
        }
        return s;
    }
};