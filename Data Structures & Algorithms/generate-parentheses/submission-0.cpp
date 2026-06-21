class Solution {
   public:
    vector<string> ans;
    void a(string& temp, int l, int r) {
        if(l == 0 && r == 0){
            ans.push_back(temp);
            return;
        }

        if(l > 0){
            temp.push_back('(');
            a(temp, l - 1, r);
            temp.pop_back();
        }

        if(r > l){
            temp.push_back(')');
            a(temp, l, r-1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        a(temp, n, n);

        return ans;
    }
};
