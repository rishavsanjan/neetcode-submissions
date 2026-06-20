class Solution {
public:
    vector<vector<int>>ans;
    void iterate(int i, int n,int k, vector<int>&temp){
        if(i > n){
            return;
        }
        

        temp.push_back(i);
        if(temp.size() == k){
            ans.push_back(temp);
        }
        iterate(i + 1, n, k, temp);

        temp.pop_back();
        iterate(i + 1, n, k, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        iterate(1, n, k, temp);

        return ans;
    }
};