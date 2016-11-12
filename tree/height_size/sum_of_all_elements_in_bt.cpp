/*
Give an algorithm for finding the sum of all 
elements in binary tree.
*/


#include <queue>
#include <cstddef>
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

	int GetSum(TreeNode* root) {
		if (root == NULL) {
			return 0;
		} else {
			return root->val + GetSum(root->left)
			    + GetSum(root->right);
		}
	}

	// with iteratively method
	int GetSum2(TreeNode* root) {
		TreeNode* temp = NULL;
		queue<TreeNode*> q;

		int sum = 0;

		if (root == NULL) {
			return 0;
		}

		q.push(root);

		while (q.empty() == false) {
			temp = q.front();
			sum += temp->val;

			if (temp->left != NULL) {
				q.push(temp->left);
			}

			if (temp->right != NULL) {
				q.push(temp->right);
			}

			q.pop();
		}

		return sum;
	}

};

int main(void) {


    return 0;
}