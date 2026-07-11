class Solution {
   public:
    map<int, vector<int>> mpp;

    bool solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }

        if (idx == nums.size()) return false;
        if (dp[idx][target] != -1) return dp[idx][target];
        bool take = false;
        if (target >= nums[idx]) {
            take = solve(idx + 1, nums, target - nums[idx], dp);
        }

        bool notTake = solve(idx + 1, nums, target, dp);

        return dp[idx][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) {
            return false;
        }
        int target = total / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return solve(0, nums, target, dp);
    }
};
