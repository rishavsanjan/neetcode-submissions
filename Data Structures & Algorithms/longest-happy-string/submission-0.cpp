class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int, char>> pq;

        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }

        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();
            ans += ch;
            if (ans.size() >= 2 && ans[ans.size() - 1] == ans[ans.size() - 2] ) {
                if (pq.empty()) break;

                auto [cnt1, ch1] = pq.top();

                pq.pop();
                ans += ch1;
                if (cnt1 - 1 > 0) {
                    pq.push({cnt1 - 1, ch1});
                }
            }

            if (cnt - 1 > 0) {
                pq.push({cnt - 1, ch});
            }
            // cout << x.first << " " << x.second << endl;
        }

        return ans;
    }
};