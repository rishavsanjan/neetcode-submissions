class Solution {
   public:
    vector<vector<int>> ans;
    void s(vector<int>& nums, int i, vector<int>& temp) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        
        temp.push_back(nums[i]);
        s(nums, i + 1, temp);
        temp.pop_back();
        int idx = i + 1;

        while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

        s(nums, idx, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        s(nums, 0, temp);

        return ans;
    }
};
