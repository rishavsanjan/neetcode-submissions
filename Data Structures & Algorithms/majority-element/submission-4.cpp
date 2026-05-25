class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>mpp;

        for(auto x : nums){
            mpp[x]++;
        }

        int largest = 0;
        int count = 0;
        for(auto x : mpp){
            if(x.second > count){
                largest = x.first;
                count = x.second;
            }
        }

        return largest;
    }
};