class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;

        for(auto x : nums){
            l = max(l, x);
            r += x;
        }


        while(l <= r){
            int mid = (l + r) / 2;

            int count = 0;
            int total = 0;
            for(auto x : nums){
                if(x + total > mid){
                    count++;
                    total = 0;
                }
                total += x;
                if(count > k){
                    break;
                }

            }

            if(count < k){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return l;
    }
};