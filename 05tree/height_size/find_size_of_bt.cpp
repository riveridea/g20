/*
Deep visit or level visit Example.

Give an algorithm for finding the size of binary tree
with recursion.
*/

/**
 * Definition for a binary tree node
 */


#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // recursive method
    int SizeOfBinaryTree1(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return SizeOfBinaryTree1(root->left) +
                1 + SizeOfBinaryTree1(root->right);
        }
    }

    // iteratively method
    int SizeOfBinaryTree2(TreeNode* root) {
        Queue<TreeNode*> q;
        TreeNode* tmp;
        int count = 0;

        if (root == NULL) {
            return 0;
        }

        q.push(root);

        while (q.empty() == false) {
            temp = q.pop();
            count++;

            if (temp->left != NULL) {
                q.push(temp->left);
            }

            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }

        return count;
    }
};
