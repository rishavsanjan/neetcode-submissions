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
    void f(TreeNode* root, TreeNode* prev, int val){
       if(root == NULL){
            TreeNode* node = new TreeNode(val);
            if(val < prev -> val){
                prev -> left = node;
            }else{
                prev -> right = node;
            }
            return;
        }
        prev = root;
        if(val < root -> val){
            f(root -> left,prev,  val);
        }else if( val > root -> val){
            f(root -> right,prev,  val);
        }
        return;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* prev = root;
        f(root, prev, val);
        return root;
    }
};