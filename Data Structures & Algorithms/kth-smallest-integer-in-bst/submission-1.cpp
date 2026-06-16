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

    void inorder(TreeNode* node, vector<int>& temp){
        if(node == NULL) return;

        inorder(node -> left, temp);
        temp.push_back(node -> val);
        inorder(node -> right, temp);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>temp;

        inorder(root, temp);
        for(auto x : temp){
            cout<<x<<" ";
        }
        return temp[k-1];
    }
};
