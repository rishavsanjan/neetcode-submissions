class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int& perimeter, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) {
            return;
        }

        grid[row][col] = -1;

        for (auto& dir : directions) {
            int new_i = row + dir[0];
            int new_j = col + dir[1];

            if (new_i < 0 || new_j < 0 || new_i >= grid.size() || new_j >= grid[0].size()) {
                perimeter++;
                continue;
            }

            if (grid[new_i][new_j] == 0) {
                perimeter++;
                continue;
            }

            if (grid[new_i][new_j] == 1) {
                dfs(grid, perimeter, new_i, new_j);
            }

           
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) { 
                    dfs(grid, perimeter, i, j);
                }
            }
        }
        return perimeter;
    }
};
