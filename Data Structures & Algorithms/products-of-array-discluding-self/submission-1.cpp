class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
    vector<int> ans(n , 1);
    vector<int> prefix(n, 1);
    vector<int> suffix(n, 1);
    

    for (int i = 1; i < nums.size(); i++)
    {
        prefix[i] = prefix[i-1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i+1] * nums[i + 1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = prefix[i] * suffix[i];
    }
    return nums;
        //vector<int>ans;
        //for(int i=0;i< nums.size(); i++){
        //    int mul = 1;
        //    for (int j = 0; j < nums.size(); j++)
        //    {
        //        if(i == j){
        //            continue;
        //        }
        //        mul = mul * nums[j];
        //    }
        //    ans.push_back(mul);

        //}
        //return ans;
    }
};
