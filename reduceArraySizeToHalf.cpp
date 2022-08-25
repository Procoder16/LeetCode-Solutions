class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        vector<int> freq;
        for(auto it:mp){
            freq.push_back(it.second);
        }
        sort(freq.rbegin(),freq.rend());
        
        int temp=0;
        for(int i=0;i<freq.size();i++){
            temp+=freq[i];
            if(temp>=n/2)
                return i+1;
            
        }
        return 0; 
    }
};