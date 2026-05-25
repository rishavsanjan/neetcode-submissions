class Solution {
public:
    int countDays(vector<int> weights,int currWeight, int dayLimit){
        int load = 0;
        int day  = 1;
        for (int i = 0; i < weights.size(); i++){
            if(load + weights[i]> currWeight){
                day++;
                load = weights[i];
            }else{
                load += weights[i];
            }
        }

        return day;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int tota_sum = 0;
        int largest = 0;
        for (int i = 0; i < weights.size(); i++){
            tota_sum += weights[i];
            if(weights[i] > largest){
                largest = weights[i];
            }
        }
        for(int i = largest;i<=tota_sum;i++){
            int ans = countDays(weights, i, days);
            if(ans <= days){
                return i;
            }
        }
        return tota_sum;
    }
};



















