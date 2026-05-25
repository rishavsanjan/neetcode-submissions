class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]){
        for(int i = 0; i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq1[26] = {0};
        for(int i = 0; i<s1.size(); i++){
            freq1[s1[i] - 'a']++;
        }

        int n = s2.size();

        for(int i = 0; i<s2.size(); i++){
            int l = 0, r= i;

            int freq2[26] = {0};
            while(l < s1.size() && r < s2.size()){
                freq2[s2[r] - 'a']++;
                l++;
                r++;
            }

            if(isFreqSame(freq1, freq2)){
                return true;
            }
        }

        return false;
    }
};
