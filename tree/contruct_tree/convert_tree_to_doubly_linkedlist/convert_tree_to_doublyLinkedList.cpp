17.13.txt

# Implement a method to convert a binary search tree into
a doubly linkedlist. The values should be kept in order and
the operation should be performed in place(that is, on the
original data structure).

           4
          / \
         2   5
        / \   \
       1   3   6
      /
     0


To: 0 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

/**
 * Definition for binary tree
 * public class TreeNode {
 *   int val;
 *   TreeNode left;
 *   TreeNode right;
 *   TreeNode(int x) {
 *     val = x;
 *   }
 * }
 */

public class Solution {
	TreeNode tree2list(Treenode root) {

		if (root == null) {
			return root;
		}

		TreeNode head = null;
		TreeNode tail = null;
		helper(head, tail, root);
		return head;
	}

	void helper(TreeNode head, TreeNode tail, TreeNode root) {
		TreeNode leftTail = null;
		TreeNode rightHead = null;

		if (root == null) {
			head = null;
			tail = null;
			return;
		}

		helper(head, leftTail, root.left);
		helper(rightHead, tail, root.right);

		if (leftTail != null) {
			leftTail.right = root;
			root.left = leftTail;
		} else {
			head = root;
		}

		if (rightHead != null) {
			rightHead.left = root;
			root.right = rightHead;
		} else {
		    tail = root;
		}
	}

}