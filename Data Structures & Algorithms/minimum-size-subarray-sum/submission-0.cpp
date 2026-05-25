class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
    int sum = 0;
    int l = 0, r = 0;
    int n = nums.size();
    while(l <= r && r < n){
        sum += nums[r];
        if(sum >= target){
            while( sum  >= target && l <= r){
                cout<<l<<" "<<r<<" : "<<sum<<endl;
                len = min(len, r - l + 1);
                sum -= nums[l];
                
                l++;
            }
            r++;
        }else{
            r++;
        }
    }

    if (len == INT_MAX){
        return 0;
    }
    return len;

    }
};