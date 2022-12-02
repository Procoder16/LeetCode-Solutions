class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int a[26],b[26];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        if(word1.size()!=word2.size())
            return false;
        
        for(int i=0;i<word1.size();i++){
            a[word1[i]-'a']++,b[word2[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(a[i]==0)
                continue;
            else
            if(a[i]==b[i]){
                a[i]=0,b[i]=0;
            }
            else{
                bool possible=false;
                for(int j=0;j<26;j++){
                    if(a[i]==b[j]&&b[i]!=0&&a[j]!=0){
                        b[j]=b[i];
                        a[i]=0,b[i]=0;
                        possible=true;
                        break;
                    }
                }
                if(!possible)
                    return false;
            }
            
        }
        for(int i=0;i<26;i++){
            if(a[i]!=0||b[i]!=0)
            return false;
        }
        return true;
    }
};