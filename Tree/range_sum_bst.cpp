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
	int ans = 0;
	int range(TreeNode* root, int low, int high) {
		if (!root)return 0;

		if (root->val > high || root->val < low)return 0;

		int l = rangeSumBST(root->left, low, high);
		int r = rangeSumBST(root->right, low, high);
		if (!(root->val > high || root->val < low)) ans += root->val;
		return l + r;
	}
	int rangeSumBST(TreeNode* root, int low, int high) {
		int x = range(root, low, high);
		return ans;
	}
};

