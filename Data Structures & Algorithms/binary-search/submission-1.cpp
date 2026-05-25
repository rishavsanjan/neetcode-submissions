class Solution {
public:
    int bs(vector<int>arr, int low, int high, int target){
        if(low > high) return -1;
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }else if (target < arr[mid]){
            return bs(arr, low, mid -1, target);
        }else{
            return bs(arr, mid+1, high, target);
        }
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = bs(nums, low, high, target);
        return ans;
        
        
    }
};
