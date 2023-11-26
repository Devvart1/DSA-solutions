#include <iostream>
#include <vector>
#include <queue>

// Define the structure of a tree node
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to insert a value into the BST
TreeNode* insert(TreeNode* root, int val) {
	if (root == nullptr) {
		return new TreeNode(val);
	}

	if (val < root->val) {
		root->left = insert(root->left, val);
	} else {
		root->right = insert(root->right, val);
	}

	return root;
}

// Function to construct a BST from an array
TreeNode* constructBSTFromArray(const int arr[], int size) {
	TreeNode* root = nullptr;

	for (int i = 0; i < size; ++i) {
		root = insert(root, arr[i]);
	}

	return root;
}

// Function to generate the left view of the BST
std::vector<int> leftView(TreeNode* root) {
	std::vector<int> result;
	if (root == nullptr) {
		return result;
	}

	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int levelSize = q.size();
		for (int i = 0; i < levelSize; ++i) {
			TreeNode* currentNode = q.front();
			q.pop();

			if (i == 0) {
				result.push_back(currentNode->val); // Leftmost node at the current level
			}

			if (currentNode->left) {
				q.push(currentNode->left);
			}
			if (currentNode->right) {
				q.push(currentNode->right);
			}
		}
	}

	return result;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	int arr[] = {4,  6, 8, 4};
	int size = sizeof(arr) / sizeof(arr[0]);

	TreeNode* root = constructBSTFromArray(arr, size);

	std::vector<int> leftViewNodes = leftView(root);

	// std::cout << "Left view of the BST: ";
	// for (int val : leftViewNodes) {
	// 	std::cout << val << " ";
	// }
	// std::cout << std::endl;
	int i = 0;
	int j = leftViewNodes.size() - 1;
	int f = 0;


	while (i < j) {
		if (leftViewNodes[i] != leftViewNodes[j]) {
			std:: cout << "NO";
			f = 1;
			break;
		}
		i++;
		--j;
	}
	if (f == 0) {
		for (int i = 0; i < leftViewNodes.size(); ++i) {
			std::cout << leftViewNodes[i];
		}
	}

	return 0;
}
