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
	typedef unsigned long long ll;
	int widthOfBinaryTree(TreeNode* root) {
		//unordered_map<TreeNode*, int> m;

		queue<pair<TreeNode*, ll>> q;

		int maxWidth = INT_MIN;
		q.push({root, 0});

		while (!q.empty()) {

			int L = q.front().second;
			int R = q.front().second;
			maxWidth = max(maxWidth, R - L + 1);
			int n = q.size();
			while (n--) {
				auto x = q.front();

				if (x.first->left)q.push({x.first->left, x.second * 2 + 1});
				if (x.first->right)q.push({x.first->right, x.second * 2 + 2});
				q.pop();
			}
		}
		return maxWidth;

	}
};