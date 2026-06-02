class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        for(int i = 0; i< mat.size(); i++){
            int l = 0;
            int r = mat[i].size() - 1;
            while(l <= r){
                int m = (l + r) / 2;
                int num = mat[i][m];
                if(num == target){
                    return true;
                }else if(num > target){
                    r = m -1;
                }else{
                    l = m + 1;
                }
            }
        }

        return false;
    }
};
