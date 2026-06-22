class Solution {
   public:
    bool solve(vector<int> nums, vector<int>& sides, int idx, int& target) {
        if (idx == nums.size()) {
            return true;
        }

        for (int i = 0; i < sides.size(); i++) {
            if (sides[i] + nums[idx] <= target) {
                sides[i] += nums[idx];

                if (solve(nums, sides, idx + 1, target)) {
                    return true;
                }

                sides[i] -= nums[idx];
                if(sides[i] == 0)
    break;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % k != 0) {
            return false;
        }

        int target = sum / k;
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;
        vector<int> sides(k, 0);

        return solve(nums, sides, 0, target);
    }
};