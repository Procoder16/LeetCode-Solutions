class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        int arr[256] = {0};
        
        int length = sentence.length();
        
        for(int i=0; i<length; i++){
            int index = (int)sentence[i];
            arr[index]++;
        }
        
        for(int i=97; i<=122; i++){
            if(arr[i]<1){
                return false;
            }
        }
        return true;
        
    }
};