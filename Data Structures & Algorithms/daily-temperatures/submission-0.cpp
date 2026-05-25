class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        ans.push_back(0);
        stack<int>st;
        
        st.push(temperatures.size() - 1);
        for (int i = temperatures.size() - 2; i >= 0; i--){
            int val = temperatures[i];
            int count = 0;
            while(!st.empty()){
                if(temperatures[st.top()] > val){
                    count += 1;
                    ans.push_back(st.top() - i);
                    st.push(i);
                    break;
                }
                count++;
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
                st.push(i);
            }
            
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
