class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
     string ans ;
     for (int i =0; i< strs.size();i++){
       string temp = strs[i];
       int j = 0;
       ans="";
       while(j < s.size() && j < temp.size() && temp[j] == s[j]){
         
         ans+=temp[j];
         j++;
       }
       s = ans;
       if (s.empty()){
         break;
       }
       
     }
    
     return ans;
    }
};