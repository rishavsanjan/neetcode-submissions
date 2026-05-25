class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            set<int> st2;
            for (int j = i + 1; j < nums.size(); j++) {
                int diff = -(nums[i] + nums[j]);
                if (st2.find(diff) != st2.end()) {
                    vector<int> temp = {nums[i], diff, nums[j]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                st2.insert(nums[j]);
            }
        }

         vector<vector<int>> ans(st.begin(), st.end());
         return ans;
    }
};
