class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        string ans = "";
        int i = 0;
        int j = 0;
        while (i < s1 && j < s2) {
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
            i++;
            j++;
        }

        if(i < s1){
            while(i < s1){
                ans.push_back(word1[i]);
                i++;
            }
        }

        if(j < s2){
            while(j < s2){
                ans.push_back(word2[j]);
                j++;
            }
        }

        return ans;
    }
};