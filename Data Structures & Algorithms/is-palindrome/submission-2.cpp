class Solution {
   public:
    bool isPalindrome(string s) {
      
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (s[l] == ' ' || ispunct(s[l])) {
                l++;
                continue;
            }
            if(s[r] == ' ' || ispunct(s[r])){
                r--;
                continue;
            }

            if(tolower(s[l]) != tolower(s[r])){
                cout<<s[l]<<" "<<s[r]<<endl;
                return false;
            }
            l++;
            r--;
        }

        return true;


    }
};
