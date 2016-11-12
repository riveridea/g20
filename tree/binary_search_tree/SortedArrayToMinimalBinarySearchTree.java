4.3.txt

# Given a sorted (incrasing order) array with unique integer elements, write an
# alogorithm to create a binary search tree with mimimal height.


TreeNode createMinimalBST(int arr[]) {
	if (arr.length == 0) {
		return null;
	} else {
		return helper(arr, 0, arr.length-1);
	}

}

TreeNode helper(int arr[], int start, int end) {
	if (start < end) {
		return null;
	}

	int mid = (start + end)/2;

	TreeNode root = new TreeNode(arr[mid]);

	root.left = helper(arr, start, mid-1);
	root.right = helper(arr, mid+1, end);

	return root;
}