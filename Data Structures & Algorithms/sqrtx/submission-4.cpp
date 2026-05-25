class Solution {
public:

    int bs(int x, int low, int high) {
        if (low > high) {
            return high;  
        }

        int mid = low + (high - low) / 2;
        long long sq = 1LL * mid * mid;

        if (sq == x) {
            return mid;
        } else if (sq < x) {
            return bs(x, mid + 1, high);
        } else {
            return bs(x, low, mid - 1);
        }
    }

    int mySqrt(int x) {
        int ans = bs(x, 0, x);
        return ans;
    }
};