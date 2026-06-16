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
    bool ans(TreeNode* node, int mini, int maxi) {
        if(node == NULL) return true;

        int val = node -> val;
        if(!(val > mini && val < maxi)){
           return false; 
        }

        return ans(node -> left, mini, val)&& ans(node -> right, val, maxi);

    }

    bool isValidBST(TreeNode* root) {
        return ans(root, INT_MIN, INT_MAX);
    }
};
