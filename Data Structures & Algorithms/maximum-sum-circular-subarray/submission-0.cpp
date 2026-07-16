class Solution {
   public:
    int kadaneMin(vector<int>& nums) {
        int sum = 0;
        int mini = INT_MAX;

        for (auto x : nums) {
            sum += x;
            mini = min(sum, mini);
            if (sum > 0) {
                sum = 0;
            }
        }

        return mini;
    }

    int kadaneMax(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;

        for (auto x : nums) {
            sum += x;
            maxi = max(sum, maxi);
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int normal = kadaneMax(nums);

        if (normal < 0) return normal;

        int minimum = kadaneMin(nums);

        return max(normal, total - minimum);
    }
};