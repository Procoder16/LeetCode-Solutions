class Solution {
public:
    string intToRoman(int num) {
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int value = num;
        string ans = "";
        for(int i = 0; i < 13; i++){
            while(value >= val[i]){
                ans += romans[i];
                value -= val[i];
            }
        }
        
        return ans;
    }
};