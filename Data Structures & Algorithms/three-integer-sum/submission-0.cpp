class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>s;
        for(int i = 0; i< n;i++){
            set<int>hashset;
            for(int j = i+1; j<n;j++){
                int target = -(nums[i] + nums[j]);

                if(hashset.find(target) != hashset.end()){
                    vector<int>temp ={nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>>ans(s.begin(), s.end());
        return ans;
    }
};
