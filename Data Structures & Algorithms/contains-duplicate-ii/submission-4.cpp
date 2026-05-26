class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;

        int l = 0;
        int r = 1;

        mpp[nums[l]]=0;

        while(r < nums.size()){
            if(mpp.find(nums[r]) != mpp.end()){
                if(abs(mpp[nums[r]] - r) <= k){
                    return true;
                }
            }
            mpp[nums[r]] = r;
            r++;
        }

        return false;
    }
};