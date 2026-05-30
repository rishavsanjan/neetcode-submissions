class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        
        for(auto x : tokens){
            if(x == "+" || x == "*" || x == "-" || x == "/"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if(x == "+"){
                    int num = num1 + num2;
                    st.push(num);
                }else  if(x == "*"){
                    int num = num1 * num2;
                    st.push(num);
                }else  if(x == "/"){
                    int num = num2 / num1;
                    st.push(num);
                }else  if(x == "-"){
                    int num =  num2 - num1;
                    st.push(num);
                } 
            }else{
                int num = stoi(x);
                st.push(num);
            }
        }

        return st.top();
    }
};
