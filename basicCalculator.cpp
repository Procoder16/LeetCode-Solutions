class Solution {
public:
    static int calc(const string &s, string::const_iterator &i)
    {
        if(i == s.end())
            return 0;
        
        int sum = 0;
        int op = 1;
        int num = 0;
        for(; i != s.end() && *i != ')'; ++i)
        {
            if(*i >= '0' && *i <= '9') {
                num = num * 10 + (*i - '0');
                continue;
            }
            
            if (*i == '-') {
                sum += op * num;
                num = 0;
                op = -1;
                continue;
            }
            if (*i == '+') {
                sum += op * num;
                num = 0;
                op = 1;
                continue;
            }
            
            if(*i == '(')
                sum += op * calc(s, ++i);
        }
        
        return sum + op * num;
    }
public:
    int calculate(string s) {
        auto i = s.cbegin();
        return calc(s, i);
    }
};