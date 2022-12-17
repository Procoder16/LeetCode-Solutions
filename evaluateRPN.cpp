#define ll long long
class Solution {
public:
    bool isOP(string str){
        return str == "+" || str == "-" || str == "*" || str == "/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string str : tokens){
            if(isOP(str)){
                ll n1 = st.top();
                st.pop();
                ll n2 = st.top();
                st.pop();

                if(str == "+") st.push(n1 + n2);
                if(str == "-") st.push(n2 - n1);
                if(str == "*") st.push(n1 * n2);
                if(str == "/") st.push(n2 / n1);
            }
            else st.push(stoi(str));
        }

        return st.top();
    }
};