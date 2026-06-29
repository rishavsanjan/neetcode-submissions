class Solution {
   public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) {
            return;
        }

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        board[row][col] = '#';

        for (auto dir : directions) {
            int nr = row + dir[0];
            int nc = col + dir[1];

            if (nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size()) {
                continue;
            }

            if (board[nr][nc] == 'X' || board[nr][nc] == '#') {
                continue;
            }

            if (board[nr][nc] == 'O') {
                dfs(board, nr, nc);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i);
            }
        }
        cout << endl;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i);
            }
        }
        cout << endl;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                   board[i][j] = 'X';
                }

                if (board[i][j] == '#') {
                   board[i][j] = 'O';
                }
            }
        }
    }
};
