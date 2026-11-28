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

    int f(TreeNode* node, int& height){
        if(node == NULL) return 0;

        int lh = f(node -> left, height);
        int rh = f(node -> right, height);

        height = max(height, abs(lh - rh));

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        int h = 0;
        f(root, h);
        if(h <= 1){
            return true;
        }
        return false;
    }
};
