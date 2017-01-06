/*
105. Construct Binary Tree from Preorder and Inorder Traversal:
https://leetcode.com/problems/construct-binary-tree-from
-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, 
construct the binary tree.

Note:You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) {
            return NULL;
        }
        
        if (preorder.size() == 0) {
            return NULL;
        }
        
        int n = preorder.size();
        
        return buildBT(preorder, 0, n-1, inorder, 0, n-1);
    }
    
    TreeNode* buildBT(vector<int>& preorder, int start1, int end1,
                    vector<int>& inorder, int start2, int end2) {
        if (start1 > end1 || start2> end2) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[start1]);
        int rootIndex = 0;
        
        for (int i = rootIndex; i <= end2; i++) {
            if (inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        
        int leftTreeSize = rootIndex-start2;
        int rightTreeSize = end2 - rootIndex;
        
        root->left = buildBT(preorder, start1+1, start1+rootIndex-start2, 
                            inorder, start2, rootIndex-1);
        root->right = buildBT(preorder, end1 + rootIndex - end2 +1, end1, 
                            inorder, rootIndex+1, end2);
        
        
        return root;
    }
};