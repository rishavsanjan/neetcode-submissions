class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}};

    int solve(int row, int col, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || col < 0 || row >= m || col >= n) {
            return INT_MAX;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        if (row == m - 1 && col == n - 1) {
            return grid[row][col];
        }

        int down = solve(row + 1, col, grid, dp);
        int right = solve(row, col + 1, grid, dp);

        return dp[row][col] = grid[row][col] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, grid, dp);
    }
};