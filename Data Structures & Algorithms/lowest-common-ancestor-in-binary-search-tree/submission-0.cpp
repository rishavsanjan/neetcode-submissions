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
    TreeNode* f(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return NULL;
        if(p -> val < node -> val && q -> val < node -> val){
            return f(node -> left, p, q);
        }else if(p -> val > node -> val && q -> val > node -> val){
            return f(node -> right, p, q);
        }

        return node;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return f(root, p , q);
       
    }
};
