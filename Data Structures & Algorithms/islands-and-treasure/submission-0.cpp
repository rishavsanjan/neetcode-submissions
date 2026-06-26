class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int count = 1;
        while (!q.empty()) {
            int size = q.size();

            while (size > 0) {
                auto [i, j] = q.front();
                q.pop();

                for(auto dir : directions){
                    int nr = i + dir[0];
                    int nc = j + dir[1];

                    if(nr <0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size()){
                        continue;
                    }

                    if(grid[nr][nc] == 2147483647){
                        grid[nr][nc] = count;
                        q.push({nr, nc});
                    }
                }
               size--;
            }
             count++;
        }

        return;
    }
};
