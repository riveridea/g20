/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes 
along the longest path from the root node 
down to the farthest leaf node.
*/

#include <iostream>
#include <cstddef>
#include <cmath>

using namespace std;
/*
 * Definition for a binary tree node
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int MaxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		} else {
			return max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
		}
	}
};

int main(void) {
    Solution c;
    TreeNode root = TreeNode(9);
    cout << c.MaxDepth(&root) << endl;

    return 0;
}