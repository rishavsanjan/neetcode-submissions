class Solution {
   public:
    vector<string> ans;
    bool isValidWord(vector<string>& wordDict, string& temp) {
        for (string s : wordDict) {
            if (s == temp) {
                return true;
            }
        }

        return false;
    }

    void solve(string s, vector<string>& wordDict, int idx, string sentence) {
        if (idx >= s.size()) {
            sentence.pop_back();
            ans.push_back(sentence);
            return;
        }

        string temp = "";
        for (int i = idx; i < s.size(); i++) {
            temp = s.substr(idx, i - idx + 1);

            if (isValidWord(wordDict, temp)) {
                string oldSentence = sentence;

                sentence += temp;
                sentence += " ";

                solve(s, wordDict, i + 1, sentence);

                sentence = oldSentence;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        string temp = "";
        solve(s, wordDict, 0, temp);
        return ans;
    }
};