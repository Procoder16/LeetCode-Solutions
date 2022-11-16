class Solution {
public:
    int guessNumber(int n) {
        int l=1;
        
         while (l <= n) {
            int m = l + (n - l) / 2;
             
            int num=guess(m);
             
            if (num==0)
                return m;

            if (num==1)
                l = m + 1;

            else
                n = m - 1;
        }
        return 0;
    }
};