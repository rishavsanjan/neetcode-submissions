class Solution {
public:

    int ans(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0){
            return nums[idx];
        }

        if(idx < 0){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int pick = nums[idx] + ans(idx - 2, nums, dp);
        int notPick = 0 + ans(idx - 1, nums, dp);
        
        
        return dp[idx] = max(pick, notPick);

    }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return ans(nums.size() -1 , nums, dp);
    }
};
