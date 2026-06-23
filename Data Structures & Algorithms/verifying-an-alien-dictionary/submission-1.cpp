class Solution {
   public:
    bool cmp(string a, string b, unordered_map<char, int> mpp) {
        int i = 0;
        int min_val = min(a.size(), b.size());
        while (i < min_val && a[i] == b[i]) i++;
        if(a.size() == i){
            return true;
        }else if(b.size() == i){
            return false;
        }

        return (mpp[a[i]] < mpp[b[i]]);
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mpp;

        for (int i = 0; i < order.size(); i++) {
            mpp[order[i]] = i;
        }

        for (int i = 1; i < words.size(); i++) {
            if (!cmp(words[i - 1], words[i], mpp)) {
                return false;
            }
        }

        return true;
    }
};