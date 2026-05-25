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
    bool f(TreeNode* node, long minVal, long maxVal){
        if (node == NULL) return true;

        if(node -> val >= maxVal || node -> val <= minVal){
            return false;
        }

        return f(node -> left, minVal, node -> val) && f(node -> right, node -> val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return f(root, LONG_MIN, LONG_MAX);
    }
};
