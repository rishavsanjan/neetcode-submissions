class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int len = 0;
        int maxFreq = 0;
        vector<int>freq(26, 0);
        while (r < n) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            int windowSize = r - l + 1;
            int replacements = windowSize - maxFreq;

            if (replacements <= k) {
                len = max(len, windowSize);
            } else {
                freq[s[l] - 'A']--;
                l++;
            }

            r++;
        }
        return len;

    }
};
