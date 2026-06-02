class Solution {
public:

    int calculateHours(int h, vector<int>& piles){
        int speed = 0;
        for(auto x : piles){
            speed += ceil((double)x / h);
        }
        cout<<speed<<endl;
        return speed;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l <= r){
            int m = (l + r) / 2;

            int hours = calculateHours(m, piles);
              
            if(hours <= h){
                 ans = m; 
                r = m - 1;
            }else if(hours > h){
                l = m + 1;
            }
        }

        return ans;
    }
};
