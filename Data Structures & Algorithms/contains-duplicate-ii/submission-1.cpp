class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int l =0;
        int r = 0;
        int n = nums.size();
        bool found  = false;
        while(r < n){
            if(mpp.find(nums[r]) != mpp.end()){
                int distance = abs(r - mpp[nums[r]]);
                if(distance <= k){
                    found = true;
                }
            }

            mpp[nums[r]] = r;
            r++;
        }
       return found;
    }
};