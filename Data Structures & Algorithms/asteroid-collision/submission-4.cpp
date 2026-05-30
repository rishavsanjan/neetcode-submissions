class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int x : asteroids) {
            if (x > 0) {
                ans.push_back(x);
            } else {
                while (!ans.empty() && x < 0 && ans.back() < abs(x) && ans.back() > 0) {
                    ans.pop_back();
                }

                if (!ans.empty() && abs(x) == ans.back()) {
                    ans.pop_back();
                } else if (ans.back() > abs(x) && !ans.empty()) {
                    continue;
                } else {
                    ans.push_back(x);
                }
            }
        }

        return ans;
    }
};