class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        map<char, int>mpp;
        int n = s.size();
        int l = 0;
        int r = 0;
        int len = 1;
        while(r < n){
            
            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                int pos = mpp[s[r]];
                
                l = pos + 1;
            }
            
            mpp[s[r]] = r;
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};
