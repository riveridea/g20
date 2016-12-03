/*
106 Construct Binary Tree from Inorder and Postorder Traversal:
https://leetcode.com/problems/construct-binary-tree-from-inorder
-and-postorder-traversal/

Given inorder and postorder traversal of a tree, construct the 
binary tree.
*/

//http://discuss.leetcode.com/questions/186/construct-binary-tree-from-inorder-and-postorder-traversal

// find root node in inorder traversal, then 
// divide the left/right subtree. Root node
// will always be the last element in post
// travseral output

/**
 * Definition for a binary tree node.
*/
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}


class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder.length != postorder.length) {
            return NULL;
        }

        if (inorder.length == 0) {
            return NULL;
        }

        return buildBT(inorder, 0, inorder.length-1, postorder, 0 postorder.length -1);
    }

    public TreeNode buildBT(int inorder[], int start1, int end1,
                            int postorder[], int start2, int end2) {
        if (start1 > end1 || start2 > end2) {
            return NULL;
        }

        // root will be the last elem in the tree postorder sorting
        TreeNode root = new TreeNode(postorder[end2]);
    }
}



    
    TreeNode* buildBT(vector<int>& inorder, int start1, int end1,
                      vector<int>& postorder, int start2, int end2) {
        if (start1 > end1 || start2 > end2) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[end2]);
        int rootIndex = -1;
        // search root node in inorder vector
        for (int i=start1; i<=end1; i++) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        
        // if these two vectors are not mactched in fact
        if (rootIndex == -1) {
            return NULL;
        }
        
        int leftTreeSize = rootIndex - start1;
        
        root->left = buildBT(inorder, start1, rootIndex-1, 
                            postorder, start2, start2 + leftTreeSize - 1);
                            
        int rightTreeSize = end1 - rootIndex;                    
        root->right = buildBT(inorder, rootIndex+1, end1,
                            postorder, end2 - rightTreeSize, end2-1);
        
        return root;
    }
};