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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* node = root;

        vector<int> in;
        while (!s.empty()) {

            if (node) {
                s.push(node);
                node = node->left;
            }
            else {
                node = s.top();
                s.pop();
                in.push_back(node->val);

                node = node->right;
            }

        }
        return in;
    }
};