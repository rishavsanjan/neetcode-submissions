class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = 0;

        while(l < nums.size()){
            if(r == nums.size()){
                l++;
                r = l;
            }

            if(nums[r] < nums[l]){
                swap(nums[l], nums[r]);
                
            }
r++;

        }

        return nums;

    }
};