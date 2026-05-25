/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;

        while(!q.empty()){
            int s = q.size();
            for(int i = 0 ; i< s;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                ans.push_back(node -> val);
            }
        }

        sort(ans.begin(), ans.end());
        for(int i =0; i<ans.size() ; i++){
            if(i == k - 1){
                return ans[i];
            }
        }

        return 0;
    }
};
