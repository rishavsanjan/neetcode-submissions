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
    int f(TreeNode* node, int& maxi){
        if(node == NULL)  return 0;
        int lh = f(node -> left, maxi);
        int rh = f(node -> right, maxi);
        maxi = max(lh + rh, maxi);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        f(root, diameter);
        return diameter;
    }
};
