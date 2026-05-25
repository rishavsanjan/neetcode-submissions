class Solution {
public:
    // void countHours(vector<int>piles, int& total_hours, int n){
    //     for(int i =0; i<piles.size(); i++){
    //         total_hours += ceil((double)piles[i] / n);
    //     }
    // }

    int countHours(vector<int>piles,  int hours){
    int total_hours = 0;
    for(int i =0; i<piles.size(); i++){
        total_hours += ceil((double)piles[i] / hours);
    }

    return total_hours;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l < r){
             int mid = l + (r - l) / 2;
            int total = countHours(piles, mid);
           if (total <= h) {
                r = mid;   
            } else {
                l = mid + 1;
            }
        }

        return l;
        // int largest  = 0;
        // for (int i = 0; i < piles.size(); i++){
        //     if(piles[i] > largest){
        //         largest = piles[i];
        //     }
        // }
        // int total_hours = 0;

        // for (int i = 1; i <= largest; i++){
        //     countHours(piles, total_hours, i);
        //     if(total_hours <= h){
        //         return i;
        //     }
        //     total_hours = 0;
        // }

        // return largest;

        }
};
