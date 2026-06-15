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
    void replace(TreeNode* toReplace, TreeNode* node, TreeNode* prev) {
        if (node == NULL) {
            prev->left = toReplace;
            return;
        }
        replace(toReplace, node->left, node);
    }

    void deleteN(TreeNode* node, TreeNode* prev, int key) {
        if (node == NULL) return;
        if (node->val == key) {
            bool isLeft = (key < prev->val);
            if (node->right) {
                if (isLeft)
                    prev->left = node->right;
                else
                    prev->right = node->right;
                replace(node->left, node->right, node->right);
                return;
            } else {
                if (isLeft)
                    prev->left = node->left;
                else
                    prev->right = node->left;
            }
        }

        if (key < node->val) {
            deleteN(node->left, node, key);
        }

        if (key > node->val) {
            deleteN(node->right, node, key);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root->left == NULL && root->right == NULL && root->val == key) {
            return NULL;
        }
        if (root->val == key) {
            if (!root->left && !root->right) return NULL;
            if (!root->right) return root->left;
            replace(root->left, root->right, root->right);
            return root->right;
        }

        deleteN(root, NULL, key);
        return root ? root : NULL;
    }
};