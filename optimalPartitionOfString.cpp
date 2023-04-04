class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        unsigned int bitmask = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int bitNumber = s[i] - 'a';
            if ((bitmask & (1 << bitNumber)) != 0) {
                count++;
                bitmask = 0;
            }
            bitmask |= (1 << bitNumber);
        }
        count++;
        return count;
    }
};