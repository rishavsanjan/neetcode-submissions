class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>st;

    void loop(vector<int>& candidates, int target,vector<int>& temp, int idx){
        if(idx >= candidates.size() || target < 0){
            if(target == 0){
                if(st.find(temp) == st.end()){
                    ans.push_back(temp);
                   st.insert(temp); 
                }
            }
            return;
        }

        temp.push_back(candidates[idx]);
        loop(candidates, target - candidates[idx], temp, idx + 1);
        temp.pop_back();
        int i = idx + 1;

        while(i < candidates.size() && candidates[i] == candidates[i - 1]){
            i++;
        }
        loop(candidates, target, temp, i);
        return;
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        loop(candidates, target, temp, 0);

        return ans;
    }
};
