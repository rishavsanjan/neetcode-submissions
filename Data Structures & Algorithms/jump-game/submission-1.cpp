class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxIndex = 0;

        for(int i = 0; i<nums.size(); i++){
            if (i > maxIndex)
                return false;
            int num = nums[i];
            maxIndex = max(maxIndex, num + i);
            if (maxIndex >= nums.size() - 1)
                return true;
        }

        return true;
    }
};
