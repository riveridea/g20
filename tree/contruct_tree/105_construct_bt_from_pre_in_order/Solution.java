/*
105. Construct Binary Tree from Preorder and Inorder Traversal:
https://leetcode.com/problems/construct-binary-tree-from
-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, 
construct the binary tree.

Note:You may assume that duplicates do not exist in the tree.
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.length != inorder.length) {
        	return null;
        }

        if (preorder.length == 0) {
        	return null;
        }

        int n = preorder.length();

        return buildTreeHelper(preorder, 0, n-1, inorder, 0, n-1);
    }

    public TreeNode buildTreeHelper(int[] preorder, int sPreorder, int ePreorder
    	    int[] inorder, int sInorder, int eInorder) {
        if (sPreorder > ePreorder || sInorder > eInorder) {
        	return null;
        }

        TreeNode root = new TreeNode(preorder[sPreorder]);
        int rootIndex = 0;

        for (int i = rootIndex; i <= eInorder; i++) {
        	if (inorder[i] == root.val) {
        		rootIndex = i;
        		break; // find the root value in inorder array,
        		// then seperate the array to two parts, each of
        		// which matches the left or right subtree.
        	}
        }

        int leftTreeSize = rootIndex - sInorder;
        int rightTreeSize = eInorder - rootIndex;

        root.left = buildTreeHelper(preorder, sPreorder+1, sPreorder + rootIndex - sInorder,
        							inorder, sInorder, rootIndex - 1);
        root.right = buildTreeHelper(preorder, ePreorder + rootIndex - eInorder + 1, ePreorder,
        							inorder, rootIndex+1, eInorder);

        return root;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
    }
}