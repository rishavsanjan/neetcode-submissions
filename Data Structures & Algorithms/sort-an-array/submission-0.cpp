class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int l = low, r = mid + 1;

    while (l <= mid && r <= high) {
        if (nums[l] <= nums[r]) {
            temp.push_back(nums[l++]);
        } else {
            temp.push_back(nums[r++]);
        }
    }

    while (l <= mid) temp.push_back(nums[l++]);
    while (r <= high) temp.push_back(nums[r++]);

    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}


    void sort(vector<int>&nums,int low , int high){
        if (low >= high) return;
        int mid;
        mid = (low + high) / 2;
        sort(nums, low, mid);
        sort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }


    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums, 0, n-1);
        return nums;

    }
};