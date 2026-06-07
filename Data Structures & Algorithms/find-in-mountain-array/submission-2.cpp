/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0;
        int r = mountainArr.length() - 1;
        int n = mountainArr.length();
        cout<<r<<endl;
        int peak = 0;
        while(l <= r){
            int m = (l + r) / 2;

            int mid =  mountainArr.get(m);
            int left = mountainArr.get(m-1);
            int right = mountainArr.get(m+1);

            if(left < mid && right < mid){
                peak = m;
                break;
            }else if(right < mid){
                r = m - 1;
            }else{
                l = m + 1;
            }

        }
         l = 0;
        r = peak;

        while (l <= r) {

            int m = l + (r - l) / 2;

            int val = mountainArr.get(m);

            if (val == target)
                return m;

            if (val < target)
                l = m + 1;
            else
                r = m - 1;
        }

        // Binary Search Right (Descending)
        l = peak + 1;
        r = n - 1;

        while (l <= r) {

            int m = l + (r - l) / 2;

            int val = mountainArr.get(m);

            if (val == target)
                return m;

            if (val > target)
                l = m + 1;
            else
                r = m - 1;
        }

        return -1;

    }
};