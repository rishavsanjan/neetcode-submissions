class Solution {
   public:
    int ans(int idx,  vector<int>& nums, vector<int>& dp) {
        
        if (idx == 0) {
            return nums[idx];
        }

        if (idx < 0) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int pick = nums[idx] + ans(idx - 2, nums, dp);
        int notPick = 0 + ans(idx - 1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size() == 1) return nums[0];
        vector<int>temp1;
        vector<int>temp2;
        for(int i = 0 ;i<nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        return max(ans(temp1.size() - 1, temp1, dp1), ans(temp2.size() - 1, temp2, dp2));
    }
};
