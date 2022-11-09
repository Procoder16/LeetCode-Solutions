class StockSpanner {
public:
    stack<pair<int, int>> st;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        if(st.empty() || st.top().first > price){
            st.push({price, 1});
            return 1;
        }
        else{
            int count = 0;
            while(!st.empty() && st.top().first <= price){
                count += st.top().second;
                st.pop();
            }
            st.push({price, count + 1});
            return count + 1;
        }
    }
};
