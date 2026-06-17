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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        queue<TreeNode*> q;
        q.push(root);
        string encoded = "";
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it == NULL) {
                encoded += "#,";
                continue;
            }
            string s = to_string(it->val);
            encoded += s;
            encoded += ",";

            if (it->left) {
                q.push(it->left);
            } else {
                q.push(NULL);
            }
            if (it->right) {
                q.push(it->right);
            } else {
                q.push(NULL);
            }
        }
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        vector<string> arr;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            arr.push_back(token);
        }
        queue<TreeNode*> q;

        TreeNode* root = new TreeNode(stoi(arr[0]));
        q.push(root);
        int i = 1;

        while (!q.empty() && i < data.size()) {
            auto it = q.front();

            q.pop();

            string s = arr[i];

            if (s == "#") {
                it->left = NULL;
            } else {
                TreeNode* node = new TreeNode(stoi(arr[i]));
                it->left = node;
                q.push(node);
            }

            i++;
            s = arr[i];

            if (s == "#") {
                it->right = NULL;
            } else {
                TreeNode* node = new TreeNode(stoi(arr[i]));
                it->right = node;
                q.push(node);
            }
            i++;
        }

        return root;
    }
};
