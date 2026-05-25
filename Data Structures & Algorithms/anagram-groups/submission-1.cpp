class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>>umap;

        for(auto x : strs){
            string s = x;
            sort(s.begin(), s.end());
            umap[s].push_back(x);
        }

        for(auto x : umap){
            vector<string> temp = x.second;
            ans.push_back(temp);
        }

        return ans;

    }
};
