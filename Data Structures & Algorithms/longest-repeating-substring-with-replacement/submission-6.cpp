class Solution {
   public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxFreq = 0;
        int maxWindow = 0;

        int arr[26] = {0};

        while (r < s.length()) {
            char c = s[r];
            arr[c - 'A']++;

            maxFreq = max(maxFreq, arr[c - 'A']);

            int windowLength = r - l + 1;

            if (windowLength - maxFreq > k) {
                arr[s[l] - 'A']--;
                l++;
            }
             windowLength = r - l + 1;

            maxWindow = max(maxWindow, windowLength);
            r++;
        }

        return maxWindow;
    }
};
