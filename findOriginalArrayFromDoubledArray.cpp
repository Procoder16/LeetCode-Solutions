class Solution {
public:
    
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 == 1){     
            return {};
        }

        
        sort(changed.begin(), changed.end());    
        unordered_map<int, int> mp;         
        
        for(auto i : changed){
            mp[i]++;
        }
        
        vector<int> ans;
        for(int i = 0 ; i < changed.size(); i++){
            if(mp[changed[i]])          
            {
                mp[changed[i]]--;       
                ans.push_back(changed[i]);  
                
                if(mp[changed[i] * 2]){       
                    mp[changed[i] * 2]--;      
                }
                else{
                    return {};            
                }
            }
        }
        return ans;     
    }
};