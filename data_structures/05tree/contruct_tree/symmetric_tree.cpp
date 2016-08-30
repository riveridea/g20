/*
Symmetric Tree:
https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror 
of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it 
both recursively and iteratively.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return (root == NULL || isSymmetricHelper(root->left, root->right));
    }

    bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
      if (left == NULL && right == NULL) {
        return true;
      } else if (left != NULL && right != NULL) {
        return (left->val == right->val) && 
            isSymmetricHelper(left->right, right->left) &&
            isSymmetricHelper(left->left, right->right);
      } else {
        return false;
      }
    }
};