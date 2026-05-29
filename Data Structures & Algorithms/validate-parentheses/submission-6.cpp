class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0) return true;
        if(s.length() == 1) return false;
        stack<char>st;

        for(char x : s){
            if(x == '(' || x == '{' || x == '['){
                st.push(x);
            }else{
                if(st.empty()) return false;
                char c = st.top();
                if(c == '{' && x != '}'){
                    return false;
                }else if(c == '(' && x != ')'){
                    return false;
                }else if(c == '[' && x != ']'){
                    return false;
                }
                st.pop();
            }
        }
        if(st.size() != 0){
            return false;
        }
        return true;
    }
};
