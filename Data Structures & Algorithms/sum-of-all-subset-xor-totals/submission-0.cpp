class Solution {
public:
    int sum = 0;
    void a(vector<int>& nums, int i, vector<int>& temp){
        if(i == nums.size()){
            int curr = 0;
            for(auto x : temp){
                cout<<x<<" ";
                curr ^= x;
            }
            sum += curr;
            cout<<endl;
            return;
        }

        temp.push_back(nums[i]);
        a(nums, i + 1, temp);

        temp.pop_back();
        a(nums, i + 1, temp);
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int>temp;
        a(nums,0,temp);

        return sum;
        
    }
};