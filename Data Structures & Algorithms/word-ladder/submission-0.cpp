class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<char, int> mpp;
        for (auto it : wordList) {
            for (auto s : it) {
                mpp[s]++;
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;

            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (auto it : mpp) {
                    word[i] = it.first;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }
};
