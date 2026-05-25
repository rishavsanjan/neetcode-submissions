class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        for(int q = 1; q<nums.size();q++){
            if(nums[p] != nums[q]){
                p++;
                nums[p] = nums[q];
            }
        }
        return p + 1;
    }
};