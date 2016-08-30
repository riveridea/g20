/*
CC150 4.1

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/


/* CPP */

/* runs in O(N) time and O(H) space */

#include<string>
#include<iostream>
#include<cmath>

using namespace std;

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
    bool isBalanced(TreeNode* root) {
        if (CheckHeight(root) == -1){
            return false;
        } else {
            return true;
        }
    }

    int CheckHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = CheckHeight(root->left);

        if (leftHeight == -1){
            return -1;
        }

        int rightHeight = CheckHeight(root->right);

        if (rightHeight == -1){
            return -1;
        }

        int heightDiff = leftHeight - rightHeight;

        if (abs(heightDiff) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }
};