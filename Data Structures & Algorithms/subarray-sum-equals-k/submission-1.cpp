class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int count = 0;

        for (auto x : nums) {
            prefixSum += x;
            int diff = prefixSum - k;
            if (mpp.find(diff) != mpp.end()) {
                count += mpp[diff];
            }
            mpp[prefixSum]++;
        }

        return count;
    }
};