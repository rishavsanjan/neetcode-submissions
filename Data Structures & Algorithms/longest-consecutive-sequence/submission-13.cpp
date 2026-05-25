class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;
        for (auto x : st) {
            int fn = x;
            int count = 1;

            while (st.find(fn + 1) != st.end()) {
                count++;
                fn++;
            }
            
            longest = max(count, longest);
            count = 0;
        }


        return longest ;
    }
};
