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
    
    void t(TreeNode* node, vector<int>&ans){
        if(node == NULL) return;

        t(node -> left, ans);
        ans.push_back(node -> val);
        t(node -> right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        t(root, ans);
        return ans;
    }
};