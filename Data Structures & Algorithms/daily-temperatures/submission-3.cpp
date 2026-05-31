class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        stack<int>st;
        for (int i = temp.size() - 1; i >= 0; i--) {
            if(st.empty()){
                st.push(temp.size() - 1);
                ans.push_back(0);
                continue;
            }

            int x = st.top();

            while(!st.empty() && temp[x] <= temp[i]){
                st.pop();
                if(!st.empty()){
                    x = st.top();
                }
            }

            if(st.empty()){
                st.push(i);
                ans.push_back(0);
            }else{
                st.push(i);
                ans.push_back(x - i);
            }


        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
