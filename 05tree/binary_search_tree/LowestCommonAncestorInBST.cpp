/*
Lowest Common Ancestor of a Binary Tree:
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) 
of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor 
is defined between two nodes v and w as the lowest node in T that has both v 
and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of 
itself according to the LCA definition.

Also, CC150 4.7
Design an algorithm and write code to find the first common ancestor of 
two nodes in a binary tree. Avoid storing additional nodes in a data structure. 
NOTE: This is not necessarily a binary search tree.

*/

// Problem 46: Given pointers to two nodes in a binary search tree, find lowest
// common ancestor (LCA). Assume that both values already exist in the tree.

// Problem 47: Give an algorithm for finding the shortest path between two nodes
// in a BST.


/**
 * Definition for a binary tree node.
 */

 struct TreeNode 
 {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
// O(n): bottom-up method to find which nodes are covered
// 在访问到leaf后结果按照bottom-up的方式向上传递
// if there is link to the parent?
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,         TreeNode* q) {
        
        if (root == NULL) {
            return NULL;
        }
        
        if (root == p || root == q) {
            return root;
        }
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        
        if (l && r) {
            return root;
        }
        
        return l? l : r;
    }
};