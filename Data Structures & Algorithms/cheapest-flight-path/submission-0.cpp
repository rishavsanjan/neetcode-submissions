class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto x : flights) {
            int u = x[0];
            int v = x[1];
            int wt = x[2];

            adj[u].push_back({v, wt});
        }
        vector<int> price(n, INT_MAX);

        queue<pair<int,pair<int,int>>> pq;
        int ans = INT_MAX;
        price[src] = 0;
        pq.push({0, {0, src}});

        while (!pq.empty()) {
            auto node = pq.front();
            pq.pop();
            int stops = node.first;
            int cost = node.second.first;
            int u = node.second.second;
            
            if(stops > k+1){
                continue;
            }
            if (u == dst) {
                ans = min(ans, cost);
            }

            for (auto x : adj[u]) {
                int v = x.first;
                int wt = x.second;

                if (cost + wt < price[v]) {
                    price[v] = cost + wt;
                    pq.push({stops + 1, {price[v], v}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};