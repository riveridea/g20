/*
116 Populating Next Right Pointers in Each Node:
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

*/

/**
 * Definition for binary tree with next pointer.
 */

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    //recursively
    void connect(TreeLinkNode *root) {
         if (root == NULL) {
             return;
         }

         if (root->left != NULL) {
             TreeLinkNode *l = root->left;
             TreeLinkNode *r = root->right;

             while (l != NULL) {
                l->next = r;
                l = l->right;
                r = r->left;
             }

             connect(root->left);
             connect(root->right);
         }
    }

    // iteratively
    void connect(TreeLinkNode *root) {
        TreeLinkNode *leftWall = root;

        while (leftWall != NULL) {
            TreeLinkNode *across = leftWall;

            while (across != NULL) {
                if (across->left != NULL) {
                    across->left->next = across->right;
                }

                if (across->right != NULL && across->next != NULL) {
                    across->right->next = across->next->left;
                }

                across = across->next;
            }

            leftWall = leftWall->left;
        }
    }
};