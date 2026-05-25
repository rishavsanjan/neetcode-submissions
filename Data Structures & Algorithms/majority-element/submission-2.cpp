class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int, int>umap;
    int count = 0;
    
    for(int i = 0; i< nums.size() ; i++){
      umap[nums[i]]++;
    }
    
    int largest = -1;
    
    for(auto it : umap){
      if((it.second > nums.size()/2)){
        largest = it.first;
      }
    }
    
    

    return largest; 
    }
};