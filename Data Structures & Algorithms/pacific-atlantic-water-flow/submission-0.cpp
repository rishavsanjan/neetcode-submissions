class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& vis, int row, int col) {
        vis[row][col] = 1;

        for (auto& dir : directions) {
            int nr = row + dir[0];
            int nc = col + dir[1];

            if (nr < 0 || nc < 0 || nr >= heights.size() || nc >= heights[0].size()) continue;

            if (vis[nr][nc]) continue;

            if (heights[nr][nc] < heights[row][col]) continue;

            dfs(heights, vis, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dfs(heights, pacific, i, 0);

        for (int j = 0; j < n; j++) dfs(heights, pacific, 0, j);

        for (int i = 0; i < m; i++) dfs(heights, atlantic, i, n - 1);

        for (int j = 0; j < n; j++) dfs(heights, atlantic, m - 1, j);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};