class Solution {
public:
    int maxArea(vector<int>& heights) {
        // int n = heights.size();
        // int area = 0;
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int currArea = min(heights[i], heights[j]) * (j - i);
        //         area = max(currArea, area);
        //     }
        // }
        // return area;
        int n = heights.size();
        int maxArea = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int currArea = min(heights[l], heights[r]) * (r - l);
            maxArea = max(maxArea, currArea);
            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;

    }
};
