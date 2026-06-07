class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int curr = 0;
        int prev = 0;
        int m = (nums1.size() + nums2.size()) / 2;
        int count = 0;

        int l = 0, r = 0;
        while (l < nums1.size() && r < nums2.size()) {
            if (count > m) {
                break;
            }
            if (nums1[l] <= nums2[r]) {
                prev = curr;
                curr = nums1[l];
                l++;
            } else {
                prev = curr;
                curr = nums2[r];
                r++;
            }

            count++;
        }

        while (l < nums1.size()) {
            if (count > m) {
                break;
            }
            prev = curr;
            curr = nums1[l];
            count++;
            l++;
        }

        while (r < nums2.size()) {
            if (count > m) {
                break;
            }
            prev = curr;
            curr = nums2[r];
            count++;
            r++;
        }

        if ((nums1.size() + nums2.size()) % 2 == 0) {
            cout << curr << " " << prev;
            double ans = double(curr + prev) / 2.0;
            return ans;
        } else {
            cout << curr << " " << prev;
            double ans = double(curr);
            return ans;
        }
    }
};
