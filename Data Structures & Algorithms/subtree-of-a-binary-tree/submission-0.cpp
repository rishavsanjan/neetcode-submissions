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

    bool f(TreeNode* node, TreeNode* subRoot ){
        if (node == NULL && subRoot == NULL) return true;
        if (node == NULL || subRoot == NULL) return false;
        

        if(node -> val == subRoot -> val){
            return f(node -> left, subRoot -> left) && f(node -> right, subRoot -> right);
        }
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;
        if (f(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
