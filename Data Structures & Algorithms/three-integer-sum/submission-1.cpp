class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i =0; i<n ;i++){
            if(i >0 && nums[i-1] == nums[i]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    vector<int>temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;

        // int n = nums.size();
        // set<vector<int>>s;
        // for(int i = 0; i< n;i++){
        //     set<int>hashset;
        //     for(int j = i+1; j<n;j++){
        //         int target = -(nums[i] + nums[j]);
        //         if(hashset.find(target) != hashset.end()){
        //             vector<int>temp ={nums[i], nums[j], target};
        //             sort(temp.begin(), temp.end());
        //             s.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans(s.begin(), s.end());
        // return ans;
    }
};
