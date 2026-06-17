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
    int maxi = INT_MIN;

    int ans(TreeNode* root) {
        if (root == NULL) return 0;
        int l = max (0, ans(root->left));
        int r = max (0, ans(root->right));

        maxi = max({maxi, l + r + root->val, l + root->val, r + root->val, root ->val});
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        ans(root);
        return maxi;
    }
};
