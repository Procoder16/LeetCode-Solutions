class Solution {
bool canTake(unordered_map<char,int> &m,string& str)
    {
        unordered_map<char,int> m1;
        for(char c: str)
        {
            if(m[c]>0 || m1[c]>0)
                return false;
            else m1[c]++;
        }
        return true;
    }
    
    void take(unordered_map<char,int> &m,string& str)
    {
        for(char c:str)
            m[c]++;
        return;
    }
    
    void unTake(unordered_map<char,int>& m,string& str)
    {
        for( char c:str)
            m[c]--;
    }
    
    int helper(vector<string>& arr,int i,int ans,unordered_map<char,int>& m)
    {
        if(i>=arr.size())
            return ans;
        
        if(ans==26)
            return ans;
        
        int temp1 = 0;int temp2 = 0;
        if(canTake(m,arr[i]))
        {
            temp1 = helper(arr,i+1,ans,m);
            take(m,arr[i]);
            temp2 = helper(arr,i+1,ans+arr[i].length(),m);
            unTake(m,arr[i]);
            return max(temp1,temp2);
        }
        
        return helper(arr,i+1,ans,m);
        
    }
public:
    int maxLength(vector<string>& arr) {
        
        int ans=0;
        unordered_map<char,int> m;
        ans = helper(arr,0,ans,m);
        return ans;
        
    }
};
