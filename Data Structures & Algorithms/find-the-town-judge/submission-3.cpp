class Solution {
   public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n, 0);

        for (int i = 0; i < trust.size(); i++) {
            count[trust[i][0] - 1]--;
            count[trust[i][1] - 1]++;
        }
        
         for(int i = 0; i < n; i++) {
            if(count[i] == n - 1) {
                return i + 1;
            }
        }

        return -1;
    }
};