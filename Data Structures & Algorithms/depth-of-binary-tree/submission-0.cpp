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

    int f(int count, TreeNode* root){
        if(root == NULL) return count;
        count++;
        int lmax = f(count, root -> left);
        int rmax = f(count, root -> right);
        return max(lmax, rmax);
    }

    int maxDepth(TreeNode* root) {
        int count = 0;
        int ans = f(0, root);
        return ans;
    }
};
