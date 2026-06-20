class Solution {
   public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void s(vector<int>& nums, int i, vector<int>& temp, int target) {
        if (i >= nums.size() || target < 0) {
            return;
        }
        if (target == 0) {
            if (st.find(temp) == st.end()) {
                ans.push_back(temp);
                st.insert(temp);
            }

            return;
        }

        temp.push_back(nums[i]);
        s(nums, i + 1, temp, target - nums[i]);
        s(nums, i, temp, target - nums[i]);

        temp.pop_back();
        s(nums, i + 1, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        s(nums, 0, temp, target);

        return ans;
    }
};
