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
    void insert(TreeNode* node, TreeNode* prev, int val) {
        if (node == NULL) {
            TreeNode* newNode = new TreeNode(val);
            if (prev->val > val) {
                prev->left = newNode;
            } else {
                prev->right = newNode;
            }
            return;
        }

        if (val < node->val) {
            insert(node->left, node, val);
        }

        if (val > node->val) {
            insert(node->right, node, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
             TreeNode* newNode = new TreeNode(val);
             root = newNode;
             return root;
        }
        insert(root, NULL, val);
        return root;
    }
};