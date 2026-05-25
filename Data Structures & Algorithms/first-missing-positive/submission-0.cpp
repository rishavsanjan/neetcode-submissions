class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // set<int>st;

        // for(auto x : nums){
        //     st.insert(x);
        // }

        vector<int>temp;
        for(auto x : nums){
            if(x <= 0){
                continue;
            }
            temp.push_back(x);
        }
        sort(temp.begin(), temp.end());
        
        int num = 0;

        for(int i = 0; i < temp.size(); i++){
            int diff = temp[i] - num;
            if(diff == 0){
                continue;
            }else if(diff == 1 ){
                num++;
            }else{
                return num + 1;
            }

        }

        return num + 1;


    }
};