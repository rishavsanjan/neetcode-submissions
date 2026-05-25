class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 0;

        for(auto x : nums){
            if(x == element){
                count++;
            }

            if(x != element){
                count--;
            }

            if(count < 0){
                element = x;
            }

            
        }
        return element;
    }
};