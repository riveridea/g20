/*

should be placed in algorithm/recursion_backtracking/dfs
all_root_2_leaf_paths.cpp

Binary Tree Paths:
https://leetcode.com/problems/binary-tree-paths/

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;

		if (root == NULL) {
			return res;
		}

		dfs(root, "", res);
		return res;
	}

	void dfs(TreeNode* root, string path, vector<string> &res) {
		path += to_string(root->val);

		if (root->left == NULL && root->right == NULL) {
			res.push_back(path);
		}

		if (root->left != NULL) {
			dfs(root->left, path + "->", res);
		}

		if (root->right != NULL) {
			dfs(root->right, path + "->", res);
		}
	}
};