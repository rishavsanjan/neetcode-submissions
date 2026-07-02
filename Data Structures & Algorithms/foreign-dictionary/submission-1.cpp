class Solution {
   public:
    bool cmp(string s2, string s1, vector<vector<int>>& adj) {
        int n = min(s1.size(), s2.size());

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                adj[s1[i] - 'a'].push_back(s2[i] - 'a');
                return true;
            }
        }

        if (s1.size() > s2.size()) {
            return false;
        }

        return true;
    }

    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        for (int i = 1; i < words.size(); i++) {
            if (cmp(words[i], words[i - 1], adj)) {
                continue;
            } else {
                return "";
            }
        }

        vector<int> present(26, 0);

        for (auto it : words) {
            for (char ch : it) {
                present[ch - 'a'] = 1;
            }
        }

        int total = 0;

        for (int x : present) total += x;

        // for (int i = 0; i < 26; i++) {
        //     cout << char(i + 'a') << " -> ";
        //     for (auto x : adj[i]) {
        //         cout << char(x + 'a') << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> indegree(26, 0);

        for (auto it : adj) {
            for (auto x : it) {
                indegree[x]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0 && present[i]) {
                q.push(i);
            }
        }
        string ans = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(char(node + 'a'));
            for (auto x : adj[node]) {
                indegree[x]--;
                if (indegree[x] == 0) {
                    q.push(x);
                }
            }
        }
        if (ans.size() != total) return "";

        return ans;
    }
};
