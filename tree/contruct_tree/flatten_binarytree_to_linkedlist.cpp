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



/*
   * preOrder:
   * 1) check, if current node is null or leaf, return it.
   * 2) init a stack to store the right child tree
   * 3) preOrder travel the tree
   * 3.1) if current node has left child, store the right child in stack, 
   *      change the left child to right.  
   * 3.2) else, get the right child from the stack and 
   *      set it as the right child as the current node
   *
   */
  public void flatten_preOrder(TreeNode root) {
    if (root == null || (root.left == null && root.right == null))
      return root;

    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode curr = root;

    while (curr != null || !stack.isEmpty()) {

      while (curr.left != null) {
        if(curr.right != null)  
            stack.push(curr.right);

        curr.right = curr.left;
        curr.left = null;
        curr = curr.right;
      }

      if (curr.right == null && !stack.isEmpty()) 
        curr.right = stack.pop();

      curr = curr.right;
    }
  }


/* recurrence: 
   * 1) if current node is null or leaf, return it.
   * 2) get the left child and right child of current node, 
   * 2.1)if the left is not null, set the left as the current node's right, 
   * flat the left tree. return the tail of left child tree as current node.
   * 2.2)if the right is not null, set the right as the current node's right, 
   * flat the right tree. return the tail of left child tree as current node.
   *   
   */
  public TreeNode flatten_recurr(TreeNode root) {
    if (root == null || (root.left == null && root.right == null))
      return root;

    TreeNode left = root.left;
    TreeNode right = root.right;

    root.left = null;

    if (left != null) {
      root.right = left;
      root = flatten_recurr(left);
    }

    if (right != null) {
      root.right = right;
      root = flatten_recurr(right);
    }

    return root;
  }