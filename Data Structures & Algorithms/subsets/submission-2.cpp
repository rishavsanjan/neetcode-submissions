class Solution {
public:
    vector<vector<int>> ans;
    void s(vector<int>& nums, vector<int>& temp, int idx) {
        if(idx >= nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        s(nums, temp, idx + 1);
        temp.pop_back();
        s(nums, temp, idx + 1);
        return;

    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        s(nums, temp, 0);
        return ans;
    }
};
