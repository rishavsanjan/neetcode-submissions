class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1) return 1;
        unordered_map<char, int> mpp;
        int l = 0;
        int r = 1;
        mpp[s[0]] = 0;

        int maxLen = 0;

        while (r < s.size()) {
            char c = s[r];
            if (mpp.find(c) != mpp.end()) {
                l = max(l, mpp[c] + 1);
            }
            maxLen = max(r - l + 1, maxLen);
            mpp[c] = r;
            r++;
        }
        if (maxLen == 0) {
            return s.size();
        }
        return maxLen;
    }
};
