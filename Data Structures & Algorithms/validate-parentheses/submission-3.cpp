class Solution {
public:
    bool isValid(string s) {
        //if(s.size() ==1) return false;
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(st.empty()) return false;
                char top = st.top();
                if (top != '('){
                    return false;
                    break;
                }
                st.pop();
            }else if(s[i] == '}'){
                if(st.empty()) return false;
                char top = st.top();
                if (top != '{'){
                    return false;
                    break;
                }
                st.pop();
            }else if(s[i] == ']'){
                if(st.empty()) return false;
                char top = st.top();
                if (top != '['){
                    return false;
                    break;
                }
                st.pop();
            }
           
        }
        if(!st.empty()){
            return false;
        }
        return true;
}
};
