/*
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of 
its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

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

	//recursively
	vector<int> InorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == NULL) {
        	return res;
        }

        Inorder(res, root);

        return res;
	}

	void Inorder(vector<int> &res, TreeNode* root) {
		if (root == NULL) {
            return;
        } else {
			Inorder(res, root->left);
			res.push_back(root->val);
			Inorder(res, root->right);
		}
	}

	// iteratively
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> allNodeValues;
        TreeNode *cur = root;
        stack<TreeNode *> s;

        while (cur || !s.empty()) {
            if (!cur) {
                cur = s.top();
                s.pop();
                allNodeValues.push_back(cur->val);
                cur = cur->right;
            } else {
                s.push(cur);
                cur = cur->left;
            }
        }

        return allNodeValues;

    }
};    