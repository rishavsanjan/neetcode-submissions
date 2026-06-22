class Solution {
   public:
    unordered_map<char, string> mpp = {{'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
                                       {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> ans;

    void solve(int idx, string s, string temp) {
        if (idx >= s.size()) {
            ans.push_back(temp);
            return;
        }

        string ch = mpp[s[idx]];

        for (int i = 0; i < ch.size(); i++) {
            temp += ch[i];
            solve(idx + 1, s, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        string temp = "";
        solve(0, digits, temp);

        return ans;
    }
};
