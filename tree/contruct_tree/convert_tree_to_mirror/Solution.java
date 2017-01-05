/*
Give an algorithm for converting a tree to its mirror. Mirror of a 
tree is another tree with left and right children of all non-leaf nodes
interchanged.
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

	public void mirror(TreeNode root) {
		printTree(root);
		TreeNode mirrorRoot = mirror(root);
		System.out.print("\n Mirroring Tree Done\n");
		printTree(mirrorRoot);
	}

    public TreeNode mirrorTree(TreeNode root) {
    	if (root != null) {
    		TreeNode node = root.left;
    		root.left = root.right;
    		root.right = node;

    		mirrorTree(root.right);
    		mirrorTree(root.left);
    	}

    	return root;
    }

    // print out in pre-order
	public void printTree(TreeNode root) {
		if (root != null) {
			printTree(root.left);
			System.out.print(""  + root.x);
			printTree(root.right);
		}
	}

	public static void main (String[] args) {

		TreeNode root = new TreeNode(4);
		root.left = new TreeNode(2);
		root.right = new TreeNode(6);

		root.left.left = new TreeNode(1);
		root.left.right = new TreeNode(3);

		root.right.left = new TreeNode(5); 
		root.right.right = new TreeNode(7);

		Solution solution = new Solution();
		solution.mirror(root);
	}
}