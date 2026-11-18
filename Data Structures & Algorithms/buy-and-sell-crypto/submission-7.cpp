class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxi = 0;
        while(r < prices.size()){
            int profit = prices[r] - prices[l];
            maxi = max(maxi, profit);
          

            if(profit < 0 || profit == 0){
                l=r;
            }
            r++;
        }

        return maxi;
    }
};
