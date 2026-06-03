class Solution {
public:
    int calculateDays(vector<int>& weights, int maxCap){
        int days = 1;
        int currCap = 0;

        for(auto x : weights){
            currCap += x;
            if(currCap > maxCap){
                days++;
                currCap = x;
            }
        }

        return days;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        

        int ans = r;
        while(l <= r){
            int m = (l + r) / 2;

            int calcDays = calculateDays(weights, m) ;

            if(calcDays <= days){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }

        }

        return ans;
    }
};




















