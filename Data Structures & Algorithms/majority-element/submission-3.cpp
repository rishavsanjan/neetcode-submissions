class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int ln = nums[0];
         int count = 0;

         for(int num : nums){
            
           if(count == 0){
             ln = num;
           }
           if(num == ln){
             count++;
             continue;
           }

           count--;
         }

         return ln;

        // unordered_map<int, int>umap;
        // int count = 0;
        // for(int i = 0; i< nums.size() ; i++){
        //   umap[nums[i]]++;
        // }
        // int largest = -1;
        // for(auto it : umap){
        //   if((it.second > nums.size()/2)){
        //     largest = it.first;
        //   }
        // }
        // return largest; 
    }
};