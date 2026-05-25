class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int>ans;
        int l = 0, r= 0, lIndex = -1, max = INT_MIN;

        while (r < nums.size()){
            if(nums[r] > max){
                max = nums[r];
                lIndex = r;
            }

            if(r - l + 1 == k){
                ans.push_back(max);
                l++;
                if(lIndex < l){
                    max = nums[l];
                    r = l;
                    continue;
                }
            }
            r++;
        }
        return ans;
    }
};
