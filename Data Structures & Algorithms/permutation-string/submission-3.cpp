class Solution {
public:
    bool areSame (int arr1[], int arr2[]){
        for(int i = 0; i< 26;i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {

        if(s2.length() < s1.length()){
            return false;
        }

        int arr1[26] = {0};
        for(int i = 0; i < s1.size(); i++){
            arr1[s1[i] - 'a']++;
        }


        int windowSize = s1.length();
        for(int i = 0; i<s2.length(); i++){
            int idx = i;
            int j = 0;

            int arr2[26] = {0};
            while(j < windowSize && idx < s2.length()){
                char c = s2[idx];
                arr2[c - 'a']++;
                j++;
                idx++;
            }

            if(areSame(arr1, arr2)){
                return true;
            }
        }


        return false;
    }
};
