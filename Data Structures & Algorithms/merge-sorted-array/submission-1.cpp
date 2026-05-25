class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int r = m;
        for (int i = 0; i < n; i++) {
            nums1[m] = nums2[i];
            m++;
        }

        int l = 0;
        while (r < nums1.size()) {
            while (l < r) {
                if (nums1[r] <= nums1[l]) {
                    swap(nums1[r], nums1[l]);
                    
                }
                l++;
               
               
            }
             l=0;
            r++;
        }
    }
};