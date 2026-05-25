class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0;
        int r = 1;
        int max_profit = 0;
        while(r < n){
            int profit = prices[r] - prices[l];
            if(profit <= 0){
                l = r;
                r++;
            }else{
                if(profit > max_profit){
                    max_profit = profit;
                }
                r++;
            }
        }
        return max_profit;
    }
};
