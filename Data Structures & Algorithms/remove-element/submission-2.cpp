class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size() - 1;
        int count = 0;
        while(l <= r){
            if(nums[l] == val){
                swap(nums[l], nums[r]);
                r--;
                count++;
                continue;
            }
            l++;
        }

        return nums.size() - count;
    }
};