class Solution {
   public:
    vector<vector<string>> ans;

    bool isPalindrome(string temp) {
        int l = 0;
        int r = temp.size() - 1;

        while (l < r) {
            if (temp[l] != temp[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void a(string s, vector<string> paritions) {
        if (s.size() == 0) {
            ans.push_back(paritions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            cout<<part<<endl;
            if (isPalindrome(part)) {
                paritions.push_back(part);
                a(s.substr(i + 1), paritions);
                paritions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> paritions;
        a(s, paritions);

        return ans;
    }
};
