class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rest = 0, sold = 0, hold = INT_MIN;
        for(auto price: prices){
            int prev_sold = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, prev_sold);
        }
        return max(sold, rest);
    }
};