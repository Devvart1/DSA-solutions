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

	void level_sum_cal(TreeNode* root, int level, unordered_map<int, int> &level_sum ) {
		if (!root)return ;
		level_sum[level] += root->val;
		level_sum_cal(root->left, level + 1, level_sum);
		level_sum_cal(root->right, level + 1, level_sum);


	}

	void sol(TreeNode* root, int level, unordered_map<int, int>  &level_sum) {
		if (root == NULL)return;
		int temp = 0;

		if (root->left)temp += root->left->val;
		if (root->right)temp += root->right->val;

		if (root->right)root->right->val = level_sum[level] - temp;

		if (root->right)root->left->val = level_sum[level] - temp;

		sol(root->left, level + 1, level_sum);
		sol(root->right, level + 1, level_sum);
	}
	TreeNode* replaceValueInTree(TreeNode* root) {
		unordered_map<int, int> level_sum;

		if (!root)return root;

		root->val = 0;

		level_sum_cal(root, 1, level_sum);
		sol(root, 1, level_sum);
		return root;
	}
};