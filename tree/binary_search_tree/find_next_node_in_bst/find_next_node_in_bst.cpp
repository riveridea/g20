/*
find_next_node_in_bst.cpp
cc150 4.6
*/

/**
 * Definition for a binary tree node.
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode *parent;
     TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
 };

 class Solution {
 	// case 1:

 	// case 2:

 	// case 3:

 	// case 4:

 public:
 	TreeNode* InorderSucc(TreeNode* node) {
 		if (node == NULL) {
 			return NULL;
 		}
 		// case 1:
 		if (node->right != NULL) {
 			return LeftMostChild(node->right);
 		} else {
 			// case 2:
 			TreeNode* q = node;
 			TreeNode* x = q->parent;

 			while (x != NULL && x->left != q) {
 				q = x;
 				x = x->parent;
 			}
 		}

 		return x;
 	}

 	TreeNode* LeftMostChild(TreeNode* n) {
 		if (n == NULL) {
 			return NULL;
 		}

 		while (n->left != NULL) {
 			n = n->left;
 		}

 		return n;
 	}

 }