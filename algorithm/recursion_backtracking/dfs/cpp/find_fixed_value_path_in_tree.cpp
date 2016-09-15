/*
 在二元树中找出和为某一值的所有路径。
 给定一个根节点。

*/

 // use backtracking and recursion

 typedef struct TreeNode {
 	struct TreeNode *left;
 	struct TreeNode *right;
 	int value;
 } TreeNode;


 void printPath(TreeNode root, int sums)
 {
 	int path[MAX_HEIGHT];
 	helper(root, sum, path, 0);
 }

 void helper(TreeNode root, int sum, int path[], int top)
 {
 	path[top++] = root.data;
 	sum -= root.data;

 	if (root.left == NULL && root.right == NULL) {
 		if (sum == 0)
 			printPath(path, top);
 	} else {
 		if (root.left != NULL)
 			helper(root.left, sum, path, top);

 		if (root.right != NULL)
 			helper(root.right, sum, path, top);

 		top--;
 		sum += root.data;
 	}
 }