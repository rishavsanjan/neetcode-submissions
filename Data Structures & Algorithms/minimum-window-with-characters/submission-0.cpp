class Solution {
public:
    string minWindow(string s, string t) {
        int hash[266] = {0};
   for (int i = 0; i < t.size(); i++){
        hash[t[i]]++;
   }
   int l = 0, r = 0;
   int minLen = INT_MAX;
   int count = 0;
   int sIndex  = -1;
   while(r < s.size()){
        if(hash[s[r]] > 0){
            count++;
            
        }
        hash[s[r]]--;
        while(count == t.length()){
            if(r - l + 1 < minLen){
                minLen = r- l + 1;
                sIndex = l;
            } 
            hash[s[l]]++;  
            if(hash[s[l]] > 0){
            count--;
            }
            l++;
        }
        r++;
   }
    if(sIndex == -1) return "";
   return s.substr(sIndex, minLen);
    }
};
