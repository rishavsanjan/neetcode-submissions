class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void bfs(vector<vector<int>>& grid, int row, int col) {}

    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        
        

        while (!q.empty() && fresh > 0) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto it = q.front();

                q.pop();
                for (auto dir : directions) {
                    int nr = it.first + dir[0];
                    int nc = it.second + dir[1];

                    if (nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()) {
                        continue;
                    }

                    if (grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        return fresh == 0 ? minutes   :-1 ;
    }
};
