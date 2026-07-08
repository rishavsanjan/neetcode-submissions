class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}};
    int ans(int row, int col, vector<vector<int>>& grid,  vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n) {
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        if (row == m - 1 && col == n - 1) {
            return 1;
        }

        int ways = 0;
        for (auto dir : directions) {
            int nr = row + dir[0];
            int nc = col + dir[1];
            ways += ans(nr, nc, grid, dp);
        }

        return dp[row][col] = ways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return ans(0, 0, grid, dp);
    }
};
