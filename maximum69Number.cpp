class Solution {
public:
    int maximum69Number (int num) {
        vector<int> a;
        
        while(num>0){
            a.push_back(num%10);
            num/=10;
        }
        
        int ans = 0;
        
        for(int i=a.size()-1; i>=0; i--){
            if(a[i]==6){
                a[i]=9;
                break;
            }
        }
        
        for(int i = a.size()-1; i>=0; i--){
            ans = ans*10 + a[i];
        }
        
        
        return ans;
    }
};