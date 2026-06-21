class Solution {
   public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void p(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            if (st.find(nums) == st.end()) {
                ans.push_back(nums);
                st.insert(nums);
            }

            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[i], nums[idx]);
            p(idx + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        p(0, nums);
        return ans;
    }
};