class Solution {
public:

    bool solve(vector<int>& arr, int idx){
        if(idx >= arr.size() - 1){
            return true;
        }

        int num = arr[idx];

        while(num > 0){
            if(solve(arr, idx + num)){
                return true;
            }
            
            num--;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
};
