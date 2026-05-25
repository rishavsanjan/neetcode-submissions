class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int>s;
    for(int i = 0; i< n ; i++){
         if(s.find(nums[i]) != s.end()){
             return true;
         }
         s.insert(nums[i]);
     }

     return false;
        // int n = nums.size();
        // set<int>s;
        // for(int i = 0; i< n ; i++){
        //     if(s.find(nums[i]) != s.end()){
        //         return true;
        //     }
        //     s.insert(nums[i]);
        // }
        // return false;

        // int n = nums.size();
        // for(int i = 0; i< n;i++){
        //     int count = 0;
        //     for(int j = 0; j < n ; j ++){
        //         if(nums[i] == nums[j]){
        //             count++;
                    
        //         }
        //         if(count == 2){
        //             return true;
        //         }
        //     }
        // }

        // return false;
    }
};