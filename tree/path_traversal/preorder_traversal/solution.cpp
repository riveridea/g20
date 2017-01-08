/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    // recursively
    // visite current node, then left tree, right tree
    vector<int> PreorderTraversal(TreeNode* root) {
        vector<int> vector;

        if (root == NULL) {
            return vector;
        }

        Preorder(res, root);

        return vector;
    }

    void Preorder(vector<int> res, TreeNode* root) {
        if (root != NULL) {
            res.add(root->val);
            Preorder(root->right);
            Preorder(root->left);
        }
    }

    // iteratively solution
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;
        TreeNode* cur = root;

        while (cur != NULL || stack.size() != 0) {
            while (cur != NULL) {
                result.push_back(cur->val);
                stack.push(cur);
                cur = cur->left;
            }

            cur = stack.top();
            stack.pop();
            cur = cur->right;
        }

        return result;
    }

};