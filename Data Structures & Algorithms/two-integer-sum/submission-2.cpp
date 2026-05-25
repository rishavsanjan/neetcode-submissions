class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int>mp;

        for(int i=0;i<n;i++){
            int diff = target - nums[i];
            if(mp.find(diff) != mp.end()){
                return {mp[diff], i};
            }
            mp[nums[i]] = i;
        }

        return {0 , 0};



        // for(int i = 0; i<=n; i++){  
        //  for(int j = i+1; j<n; j++){
        //     int sum = 0;
        //     if(nums[i] + nums[j] == target){
        //         return {i, j};
        //     }
        //  }
        // }

    }
};
