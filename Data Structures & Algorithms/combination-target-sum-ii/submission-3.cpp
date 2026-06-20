class Solution {
   public:
    vector<vector<int>> ans;
    set<vector<int>> s;

    void a(vector<int>& nums, vector<int>& temp, int target, int i) {
        if (target == 0) {
            if (s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }

        if (i >= nums.size() ||  target < 0) {
            return;
        }


        

        temp.push_back(nums[i]);
        a(nums, temp, target - nums[i], i + 1);
        // a(nums, temp, target - nums[i], i);
        temp.pop_back();
         int idx = i + 1;

         while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;
        a(nums, temp, target, idx);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        a(candidates, temp, target, 0);
        return ans;
    }
};
