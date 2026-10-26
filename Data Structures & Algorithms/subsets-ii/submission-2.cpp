class Solution {
public:

    vector<vector<int>>ans;
    void f(int i, vector<int>& nums, vector<int>&temp){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(i + 1, nums, temp);
        temp.pop_back();
        int idx = i + 1;
        while(idx < nums.size() && nums[idx-1] == nums[idx]) idx++;
        f(idx, nums, temp);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        f(0, nums, temp);
        return ans;
    }
};
