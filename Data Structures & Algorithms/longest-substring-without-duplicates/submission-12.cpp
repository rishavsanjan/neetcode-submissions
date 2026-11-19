class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l = 0;
        int r = 0;
        int ans = 0;
        while (r < s.size()) {
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                int pos = mpp[s[r]];
                l = pos + 1;
            }
            ans = max(ans, r - l + 1);
            mpp[s[r]] = r;
            r++;
        }

        return ans;
    }
};
