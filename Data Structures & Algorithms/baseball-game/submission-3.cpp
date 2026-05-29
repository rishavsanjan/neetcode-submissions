class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;

        for(auto x : operations){
            if(x == "+"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top() + num1;
                st.push(num1);
                st.push(num2);

            }else if(x == "D"){
                int num = st.top();
                st.push(num * 2);
            }else if(x == "C"){
                st.pop();
            }else{
                int num = stoi(x);
                st.push(num);
            }
        }

        int sum = 0;
        while(!st.empty()){
            int num = st.top();
            sum += num;
            st.pop();
        }

        return sum;


    }
};