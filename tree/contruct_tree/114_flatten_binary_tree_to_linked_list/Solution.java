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
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {

    // recursively, connecct the right most node of a node to it right node
    // use tree preorder
    public TreeNode flatten(TreeNode root) {
        if (root == null) {
          return;
        }  

        TreeNode left = root.left;
        TreeNode right = root.right;

        root.left = null;

        if (left != null) {
          root.right = left;
          root = flatten(left);
        }

        if (right != null) {
          root.right = right;
          root = flatten(right);
        }

        return root;
    }

    /*
    * preOrder:
    * 1) check, if current node is null or leaf, return it.
    * 2) init a stack to store the right child tree
    * 3) preOrder travel the tree
    * 3.1) if current node has left child, store the right child in stack, 
    *      change the left child to right.  
    * 3.2) else, get the right child from the stack and 
    *      set it as the right child as the current node
    */

    public void flatten2(TreeNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return;
        }

        Stack<TreeNode> stack = new Stack<TreeNode>();
        TreeNode current = root;

        while (current != null || !stack.isEmpty()) {
            while (current.left != null) {
                if (current.right != null) {
                    stack.push(current.right);
                }

                current.right = current.left;
                current.left = null;
                current = current.right;
            }

            if (current.right == null && !stack.isEmpty()) {
                current.right = stack.pop();
            }
        }
    }


}