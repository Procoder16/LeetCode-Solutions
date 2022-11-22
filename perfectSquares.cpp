class Solution {
public:
    int numSquares(int n){
    vector<int> hMap(n+1, -1);
    vector<int> found;
    for(int j = 1; j*j <= n ;j++)
    {
        hMap[j*j] = 1;
        found.push_back(j*j);        
    }
    if(hMap[n] != -1) return hMap[n];
    int count = 2;
    int offset = 0;
    while(count<=3){
        int currentSize = found.size();
        for(int i= 0 + offset ;i<currentSize;i++){
            for(int j =1; j*j < n; j++){
                int temp = found[i]+ j*j;
                if(temp>n || hMap[temp] != -1) continue;
                found.push_back(temp);
                hMap[temp] = count;
            }
        }
        if(hMap[n] != -1) return count;
        offset = currentSize;
        count++;
    }
    return 4;
}
};