class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>umap;
	
     vector<vector<string>>ans;
         for(int i = 0; i<strs.size();i++){
             string temp = strs[i];
             sort(temp.begin(), temp.end());
             
                 umap[temp].push_back(strs[i]);
            
         }
         
        for (auto it : umap) {
        vector<string>temp;
        for (auto &s : it.second) {
            temp.push_back(s);
        }
        ans.push_back(temp);
        }
        return ans;
    }
};
