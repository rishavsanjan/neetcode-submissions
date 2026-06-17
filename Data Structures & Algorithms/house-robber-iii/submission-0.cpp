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
    int rob(TreeNode* root) {
        vector<int>t = ans(root);

        return max(t[0], t[1]);
    }


    vector<int> ans(TreeNode* root){
        if(root == NULL){
            vector<int> t(2, 0);
            return t;
        }

        vector<int> left = ans(root -> left);
        vector<int> right = ans(root -> right);

        vector<int> options(2, 0);

        options[0] = root -> val + left[1] + right[1];
        options[1] = max(left[0], left[1]) + max(right[0], right[1]);


        return options;
    }
};