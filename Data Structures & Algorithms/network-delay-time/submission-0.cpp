class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto x : times) {
            adj[x[0]].push_back({x[1], x[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int u = it.second;

            for (auto x : adj[u]) {
                int v = x.first;
                if (wt + x.second < dist[v]) {
                    dist[v] = wt + x.second;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(dist[i], ans);
        }

        return ans;
    }
};
