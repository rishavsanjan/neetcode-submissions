class Solution {
public:


    bool isAnagram(string s, string t) {
        vector<int>arr1(26, 0);
        vector<int>arr2(26, 0);

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            int unicode = (int)ch;
            arr1[unicode - 97]+=1;
        }
        for(int i = 0; i < t.size(); i++){
            char ch = t[i];
            int unicode = (int)ch;
            arr2[unicode - 97]+=1;
        }
        for(int i = 0; i < 26; i++){
            if(arr1[i]  != arr2[i]){
                return false;
            }
        }

        return true;
    }
};
