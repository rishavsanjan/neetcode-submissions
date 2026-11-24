class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0;
        int r = rows * cols - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            int row = m / cols;
            int col = m % cols;

            int num = matrix[row][col];
            if (num == target) {
                return true;
            } else if (num > target) {
                r = m - 1;

            } else {
                l = m + 1;
            }
        }
        return false;
    }
};
