class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
    stack<int>st;
    int score = 0;
    for (int i = 0; i < n; i++){
        if(operations[i] == "+"){
            int top1= st.top();
            st.pop();
            int top2 = st.top();
            st.push(top1);
            int ans = top1 + top2;
            st.push(ans);
        }else if(operations[i] == "D"){
            int top = st.top();
            int ans = 2* top;
            st.push(ans);
        }else if(operations[i] == "C"){
            st.pop();
        }else{
            int point = stoi(operations[i]);
           st.push(point);  
        }
    }

    while(!st.empty()){
        int top = st.top();
        score+=top;
        st.pop();
    }
    return score;
    }
};