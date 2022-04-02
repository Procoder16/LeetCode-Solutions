#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool helper(int i,int j,string &s,int ans)
    {
        if(ans > 1)
            return false;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return helper(i+1,j,s,ans+1) || helper(i,j-1,s,ans+1);
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i =0;
        int j = s.size()-1;
        int ans = 0;
        return helper(i,j,s,ans);
    }
};