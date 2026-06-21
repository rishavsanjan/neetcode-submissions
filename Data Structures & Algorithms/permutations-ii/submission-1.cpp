class Solution {
   public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    void p(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            // if (st.find(nums) == st.end()) {
                ans.push_back(nums);
                // st.insert(nums);
            // }

            return;
        }

        set<int>used;
        for (int i = idx; i < nums.size(); i++) {
            if(used.count(nums[i])) continue;

            used.insert(nums[i]);
            swap(nums[i], nums[idx]);
            p(idx + 1, nums);
            
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        p(0, nums);
        return ans;
    }
};