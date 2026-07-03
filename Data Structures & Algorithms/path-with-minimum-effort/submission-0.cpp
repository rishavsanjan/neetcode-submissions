class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int n = heights.size();
        int m = heights[0].size();
        pq.push({0, {0, 0}});

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        dist[0][0] = 0;

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int diff = node.first;
            int row = node.second.first;
            int col = node.second.second;
            for (auto dir : directions) {
                int nr = row + dir[0];
                int nc = col + dir[1];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                    continue;
                }

                int edgeDiff = abs(heights[nr][nc] - heights[row][col]);

                int newDiff = max(diff, edgeDiff);

                if (newDiff < dist[nr][nc]) {

                    dist[nr][nc] = newDiff;
                    pq.push({newDiff, {nr, nc}});
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
