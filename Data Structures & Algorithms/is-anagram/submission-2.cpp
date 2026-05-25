class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> freq;

        for (char x : s) {
            freq[x]++;
        }

        for (int i = 0; i < t.size(); i++) {
            freq[t[i]]--;
             if (freq[t[i]] < 0) {
                return false;
            }
        }

        return true;
    }
};
