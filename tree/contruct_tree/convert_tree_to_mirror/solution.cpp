/*
Give an algorithm for converting a tree to its mirror. Mirror of a 
tree is another tree with left and right children of all non-leaf nodes
interchanged.
*/


/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */


 /* Java */
 /*
输入一个二元查找树，将该树转化成它的镜像。 递归和循环。
*/

class TreeNode {
	TreeNode right;
	TreeNode left;
	int value;
}


public void swap(TreeNode l, TreeNode r) {
	TreeNode tmp = l;
	l = p;
	p = tmp;
}


public mirror(TreeNode root) {

	if (root == NULL) 
		return;

	swap(root.left, root.right);
	mirror(root.left);
	mirror(root.right);

}



public mirror_iterate(TreeNode root) {
	if (root == NULL) {
		return;
	}

	Stack<Node> stack = new Stack<Node>;
	stack.push(root);

	while (!stack.empty()) {
		TreeNode n = stack.pop();
		swap(root.left, root.right);

		if (root.left != NULL) {
			stack.push(root.left);
		}

		if (root.right != NULL) {
			stack.push(root.right);
		}
	}


}