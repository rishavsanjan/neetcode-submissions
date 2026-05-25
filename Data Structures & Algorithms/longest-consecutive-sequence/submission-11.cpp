class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        set<int>st; 

        for(auto x : nums){
            st.insert(x);
        }

        int count = 0;
        int longest = 0;

        vector<int>temp(st.begin(), st.end());

        for(int i = 1; i < temp.size(); i++){
            cout<<temp[i-1]<<"-"<< temp[i]<<endl;
            cout<<abs(temp[i-1] - temp[i])<<endl;
            if(abs(temp[i] - temp[i-1]) == 0){
                continue;
            }
            if(abs(temp[i] - temp[i-1]) > 1){
                longest = max(count, longest);
                count = 0;
                continue;
            }
            cout<<count<<endl;
            count++;
        }

        longest = max(count, longest);

        return longest + 1;
        
    }
};
