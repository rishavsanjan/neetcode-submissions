class Solution {
   public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        string ans = "";
        map<char, int> mpp;
        for (auto x : s) {
            mpp[x]++;
        }

        for (auto x : mpp) {
            pq.push({x.second, x.first});
        }

        while (pq.size() >= 2) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            auto [cnt2, ch2] = pq.top();
            pq.pop();

            ans += ch1;
            ans += ch2;

            if (cnt1 - 1 > 0) pq.push({cnt1 - 1, ch1});
            if (cnt2 - 1 > 0) pq.push({cnt2 - 1, ch2});
        }

        if (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();
            if (cnt > 1) {
                return "";
            }else{
                ans += ch;
            }
        }

        return ans;
    }
};