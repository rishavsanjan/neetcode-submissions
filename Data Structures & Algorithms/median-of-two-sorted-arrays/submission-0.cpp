class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int l = 0, r = 0;
        while (l < nums1.size() && r < nums2.size()) {
            if (nums1[l] < nums2[r]) {
                temp.push_back(nums1[l]);
                l++;
            } else if (nums1[l] == nums2[r]) {
                temp.push_back(nums1[l]);
                temp.push_back(nums2[r]);
                l++;
                r++;
            } else {
                temp.push_back(nums2[r]);
                r++;
            }
        }

        while (l < nums1.size()) {
            temp.push_back(nums1[l]);
            l++;
        }

        while (r < nums2.size()) {
            temp.push_back(nums2[r]);
            r++;
        }

        for (auto x : temp) {
            cout << x << " ";
        }

        if (temp.size() % 2 == 0) {
            int m = temp.size() / 2;
            cout<<endl;
            cout<<double(temp[m]+temp[m-1])/2;
            return double(temp[m]+temp[m-1])/2;

        } else {
            int m = temp.size() / 2;

            double ans = temp[m];

            return ans;
        }

        

        // return 0.0;
    }
};
