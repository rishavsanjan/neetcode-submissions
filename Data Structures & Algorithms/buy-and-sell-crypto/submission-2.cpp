class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int bestBuy = INT_MAX;;
        for(int i = 0; i<prices.size() ; i++){
            if(prices[i] < bestBuy){
                bestBuy = prices[i];
            }

            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }

        return maxProfit;
    }
};
