class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
             stack<int> st;
    int n = asteroids.size() - 1;
    int i = 1;

    st.push(asteroids[0]);

    while (i <= n) {

        int val = asteroids[i];
        bool destroyed = false;

        // Collision only when top > 0 and val < 0
        while (!st.empty() && st.top() > 0 && val < 0) {

            if (abs(st.top()) < abs(val)) {
                st.pop();                  // top destroyed
            }
            else if (abs(st.top()) == abs(val)) {
                st.pop();                  // both destroyed
                destroyed = true;
                break;
            }
            else {
                destroyed = true;          // val destroyed
                break;
            }
        }

        if (!destroyed) {
            st.push(val);
        }

        i++;
    }

    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};