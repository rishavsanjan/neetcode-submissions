class Solution {
   public:
    bool transverse(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
         set<char>st;
        for(int i = sr; i< er;i++){
           
            for(int j =sc; j< ec;j++){
                char x = board[i][j];
                if (x == '.') {
                    continue;
                }

                if (st.find(x) != st.end()) {
                    return false;
                }

                st.insert(x);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                char x = board[i][j];
                if (x == '.') {
                    continue;
                }

                if (st.find(x) != st.end()) {
                    return false;
                }

                st.insert(x);
            }
        }

        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                char x = board[j][i];
                if (x == '.') {
                    continue;
                }

                if (st.find(x) != st.end()) {
                    return false;
                }

                st.insert(x);
            }
        }

        for (int sr = 0; sr < 9; sr+=3) {
            int er = sr + 3;
            for (int sc = 0; sc < 9; sc+=3) {
                int ec = sc + 3;
                if (!transverse(board, sr, er, sc, ec)) {
                    return false;
                }
            }
        }

        return true;
    }
};
