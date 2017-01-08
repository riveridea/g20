/*
104. Maximum Depth of Binary Tree
https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes 
along the longest path from the root node 
down to the farthest leaf node.
*/

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public int maxDepth(TreeNode root) {
        if (root == null) {
        	return 0;
        } else {
        	return max(maxDepth(root->left), maxDepth(roo->right)) + 1;
        }
    }

    public static void main(String[] args) {

    }
}