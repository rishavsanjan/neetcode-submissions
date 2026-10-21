class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;

    void s(vector<int>& nums, vector<int>& temp, int target, int idx){
        if(idx == nums.size() || target < 0){
            if (target == 0) {
                if (st.find(temp) == st.end()) {
                     ans.push_back(temp);
                     st.insert(temp);
                }
                
            }

            return;
        }

        temp.push_back(nums[idx]);
        s(nums, temp, target - nums[idx], idx + 1);
        s(nums, temp, target - nums[idx], idx);
        temp.pop_back();

        s(nums, temp, target, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        s(nums, temp, target, 0);
        return ans;
    }
};
