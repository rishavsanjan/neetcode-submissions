class Solution {
   public:
    int largestRectangleArea(vector<int>& h) {
        int maxArea = 0;
        stack<int> st;
        for (int i = 0; i < h.size(); i++) {
            while (!st.empty() && h[st.top()] > h[i]) {
                int ele = st.top();
                st.pop();
                int pse;
                if (st.empty()) {
                    pse = -1;
                } else {
                    pse = st.top();
                }
                int nse = i;

                maxArea = max(maxArea, (nse - pse - 1) * h[ele]);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int ele = st.top();
            st.pop();

            int nse = h.size() ;
            int pse;
            if (st.empty()) {
                pse = -1;
            } else {
                pse = st.top();
            }

             maxArea = max(maxArea, (nse - pse - 1) * h[ele]);
        }

        return maxArea;
    }
};
