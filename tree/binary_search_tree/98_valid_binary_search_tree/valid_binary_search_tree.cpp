/*
98. Validate Binary Search Tree:
https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary s
earch tree (BST).
Assume a BST is defined as follows:
1. The left subtree of a node contains only nodes with keys less 
than the node's key.
2. The right subtree of a node contains only nodes with keys greater 
than the node's key.
3. Both the left and right subtrees must also be binary search trees.
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



/* Java */

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return validateBST(root, INT_MIN, INT_MAX);
    }
    
    bool validateBST(TreeNode *root, int minVal, int maxVal) {
        if(!root) return true;
        if(root->val<=minVal || root->val>=maxVal) return false;
        return validateBST(root->left, minVal, root->val) && validateBST(root->right, root->val, maxVal);
    }
};

// way2:
/*
1. 对一个BST进行inorder traverse，必然会得到一个严格单调递增序列，
否则则是invalid BST。
2. Inorder traverse时并不需要记录下整个访问过的序列，而只需要保存
前一个访问的节点数值就可以了。
ln 10:检验左子树是否valid，并通过引用得到左子树的最大值curMax。

ln 11-12:在左子树valid的情况下，判断当前节点是否大于curMax。在当前
节点也valid的情况下，更新curMax为当前节点。

ln 13:当左子树和当前节点都valid时，返回右子树的检验结果即可。
*/

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int curMax = INT_MIN;
        return validateBST(root, curMax);
    }
    
    bool validateBST(TreeNode *root, int &curMax) {
        if(!root) return true;
        if(!validateBST(root->left, curMax)) return false;
        if(curMax >= root->val) return false;
        curMax = root->val;
        return validateBST(root->right, curMax);
    }
};



/*
public class Solution {
   public boolean isValidBST(TreeNode root) {
        return isBSTHelper(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    public boolean isBSTHelper(TreeNode node, int low, int high) {
    	if (node == null) {
    		return true;
    	}

    	if (low < node.val && node.val < high) {
    		return isBSTHelper(node.left, low, node.val) &&
    			isBSTHelper(node.right, node.val, high);
    	} else {
    		return false;
    	}
    }

}

/*
# Do In-Order Traversal of the given tree and store the result in a temp array.
# Check if the temp array is sorted in ascending order, it it is, then the tree
# is BST. Or we can avoid the use of Auxiliary Array. While doing In-Order traversal,
we can keep track of previously visited node. If the value of the currently visited
node is less than the previous value, then tree is not BST.
*/
/*
bool isBST(struct node *root)
{
    static struct node *prev = NULL;

    if (root)
    {
        if(!isBST(root->left))
            return false;

        if (prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }

    return true;
}
*/