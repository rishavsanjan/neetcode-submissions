class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void solve(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return;
        }

        grid[row][col] = '2';
        for (auto& dir : directions) {
            int new_i = row + dir[0];
            int new_j = col + dir[1];

            if (new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid[0].size()) {
                continue;
            }

            if (grid[new_i][new_j] == '0') {
                continue;
            }

            if (grid[new_i][new_j] == '1') {
                solve(grid, new_i, new_j);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    solve(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
