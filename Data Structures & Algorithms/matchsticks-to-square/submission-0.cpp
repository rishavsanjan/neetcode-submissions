class Solution {
   public:
    bool solve(int idx, vector<int> matchsticks, vector<int>& sides, int target) {
        if(idx == matchsticks.size()){
            return true;
        }


        for(int i = 0; i<4;i++){
            if(sides[i] + matchsticks[idx] <= target){
                sides[i] += matchsticks[idx];

                if(solve(idx + 1, matchsticks, sides, target)){
                    return true;
                }

                sides[i] -= matchsticks[idx];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int perimeter = 0;

        for (int i = 0; i < matchsticks.size(); i++) {
            perimeter += matchsticks[i];
        }

        if (perimeter % 4 != 0) {
            return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());

        
        int target = perimeter / 4;
        if(matchsticks[0] > target){
            return false;
        }
        vector<int> sides(4, 0);

        return solve(0, matchsticks, sides, target);

    }
};