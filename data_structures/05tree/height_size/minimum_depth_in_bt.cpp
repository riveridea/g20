/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the
shortest path from the root node down to the nearest 
leaf node.
*/

#include <cstddef>
#include <iostream>
#include <cmath>

using namespace std;


/*
 * Definition of a binary tree node
 */

class Solution {
public:
	int FindMin(TreeNode* root) {
		if (root == NULL) {
			return 0;
		} else {

			if (root->left == NULL && root->right == NULL) {
				return 1;
			} else {
				return FindMinHelper(root, 1);
			}
		}
	}

	int FindMinHelper(TreeNode* root, int depth) {
		if (root == NULL) {
			return depth -1;
		}

		int depthL = FindMinHelper(root->left, depth + 1);
		int depthR = FindMinHelper(root->right, depth + 1);

		if (depthL == depth) {
			return depthR;
		}

		if (depthR == depth) {
			return depthL;
		}

		return depthL < depthR ? depthL : depthR;
	}

};

int main(void) {


	return 0;
}