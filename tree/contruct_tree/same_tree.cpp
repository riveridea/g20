/*
Given two binary trees, write a function to check 
if they are equal or not.

Two binary trees are considered equal if they 
are structurally identical and the nodes have 
the same value.
*/

#include <queue>
#include <cstddef> 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* IsSameTree(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        }

        if (t1 == NULL && t2 != NULL) {
            return false;
        }

        if (t1 != NULL && t2 == NULL) {
            return false;
        }

        return (t1->val == t2->val && 
            IsSameTree(t1->left, t2->left) &&
            IsSameTree(t1->right, t2->right));
    }
};