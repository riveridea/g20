/*
输入一个二元查找树，将该树转化成它的镜像。 递归和循环。
*/

typedef struct _TreeNode {
	struct _TreeNode *right;
	struct _Treenode *left;
	int value;
} TreeNode;

void swap(node l, node r) {
	node p = l;
	l = r;
	r = p;
}

void mirror(TreeNode root)
{
	if (root == NULL)
		return;

	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}

void mirror1(TreeNode root) {
	if (root == NULL) {
		return;
	}

	stack<Node> buf;
	buf.push(root);

	while (!stack.empty()) {
		TreeNode n = stack.pop();
		swap(root.left, root.right);

		if (root.left != NULL)
			buf.push(root.left);
		if (root.right != NULL) 
			buf.push(root.right);
	}
}