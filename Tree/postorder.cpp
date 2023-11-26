/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  void printkthlevel(TreeNode* root, int k, vector<int> &ans, int level) {

    if (!root)return ;

    if (k == level)
      ans.push_back(root->val);
    printkthlevel(root->left, k, ans, level + 1);
    printkthlevel(root->right, k, ans, level + 1);


  }

  int helper(TreeNode* root, TreeNode* target, int k, vector<int> &ans) {
    if (!root)return -1;

    if (root == target)
    {
      printkthlevel(root, k, ans, 0);
      return 0;
    }

    int DL = helper(root->left, target, k, ans);
    if (DL != -1) {
      if (DL + 1 == k)
      {
        ans.push_back(root->val);
      }
      else {

        printkthlevel(root->right, k - DL - 2, ans, 0);
      }
      return DL + 1;
    }
    int DR = helper(root->right, target, k, ans);
    if (DR != -1) {
      if (DR + 1 == k)
      {
        ans.push_back(root->val);
      }
      else {

        printkthlevel(root->left, k - DR - 2, ans, 0);
      }
      return DR + 1;
    }
    return -1;
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;

    int x = helper(root, target, k, ans);
    return ans;
  }
};