class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int l = 0;
        int r = 0;
        while(l <= min(word1.size() - 1, word2.size() - 1)){
            result += word1[l];
            result += word2[r];
            l++;
            r++;
        }
        while(l <= word1.size() - 1){
            result += word1[l];
            l++;
        }
        while(r <= word2.size() - 1){
            result += word2[r];
            r++;
        }
        return result;
    }

};