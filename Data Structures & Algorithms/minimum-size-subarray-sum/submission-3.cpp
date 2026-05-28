class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int r = 0;
        int minLen = INT_MAX;
        int sum = 0;
        while(r < nums.size()){
            sum += nums[r];

            if(sum >= target){
                minLen = min(minLen, r- l +   1);
                while(sum - nums[l] >= target){
                    sum -= nums[l];
                    l++;
                    minLen = min(minLen, r- l +   1);
                }
            }
            r++;
        }

        if(minLen == INT_MAX){
            return 0;
        }

        return minLen;
    }
};