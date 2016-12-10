/*
114. Flatten Binary Tree to Linked List
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points 
to the next node of a pre-order traversal.

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

    // recursively, connect the right most node of a node to
    // it right node.
    void flatten(TreeNode* root) {
      if (root == NULL) {
          return;
      }
      
      TreeNode* left = root->left;
      TreeNode* right = root->right;
      
      if (left != NULL) {
          root->right = left;
          root->left = NULL;
          
          TreeNode* rightmost = left;
          
          while (rightmost->right != NULL) {
              rightmost = rightmost->right;
          }
          
          rightmost->right = right;
      }
      
      flatten(root->right);       
    }
};