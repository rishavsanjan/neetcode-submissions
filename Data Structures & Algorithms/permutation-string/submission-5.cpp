class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
            
        }
        int n = s2.size();
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (auto x : s1) {
            freq1[x - 'a']++;
        }

        int l = 0;
        int r = 0;
        int winSize = s1.size();
        while(r < n){
            freq2[s2[r] - 'a']++;

            if(r - l + 1 > winSize){
                freq2[s2[l] - 'a']--;
                l++;
            }
            if(freq1 == freq2){
                return true;
            }
            r++;
        }
        
        
        return false;
    }
};
