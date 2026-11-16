class Solution {
   public:
    int maxArea(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        int maxi = 0;
        while (l < r) {
            int mini = min(arr[l], arr[r]);
            maxi = max(maxi, mini * (r - l));
            cout<<maxi<<" ";
            if (arr[l] <= arr[r]) {
                l++;
            } else {
                r--;
            }
        }

        return maxi;
    }
};
