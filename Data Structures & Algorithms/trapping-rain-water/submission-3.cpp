class Solution {
   public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;

        while (l <= r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax < rightMax){
                ans += leftMax - height[l];
                l++;
            }else{
                 ans += rightMax - height[r];
                r--;
            }
        }

        return ans;
    }
};
