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
    void f(TreeNode* node, int& count, int largest){
        if(node == NULL) return;
        if(node -> val >= largest){
            count++;
        }
        largest = max(node -> val, largest);
        f(node -> left, count, largest);
        f(node -> right, count, largest);
        
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        f(root, count, root -> val);
        return count;
    }
};
