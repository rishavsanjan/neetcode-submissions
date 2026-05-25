class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int>freq;
        for(int x : nums){
            freq[x]++;
        }

        for(auto x : freq){
            if(x.second > 1){
                return true;
            }
        }

        return false;

    }
};