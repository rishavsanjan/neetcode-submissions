class Solution {
   public:
    string decodeString(string s) {
        stack<string> stS;
        stack<int>stN;
        int num = 0;
        string curr = "";
        for (char x : s) {
            if (isdigit(x)) {
                 num = num * 10 + (x - '0');
                
            }else if(x == '[') {
                stN.push(num);
                stS.push(curr);

                num = 0;
                curr = "";
            }else if(x == ']'){
                int repeat = stN.top();
                stN.pop();

                string prev = stS.top();
                stS.pop();
                string temp = "";
                for(int i = 0; i<repeat;i++){
                    temp += curr;
                }

                curr = prev + temp;
            }else{
                curr += x;
            }
        }

        return curr;
    }
};