/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
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
    vector<int> PostorderTraversal(TreeNode* root) {
        vector<int> vector;

        if (root == NULL) {
            return vetor;
        }

        Postorder(res, root);

        return vector;
    }

    void Postorder(vector<int> res, TreeNode* root) {
        if (root != NULL) {
            Postorder(res, root->left);
            Postorder(res, root->right);
            res.add(root->val);
        }
    }


    // iteratively 
    vector<int> PostorderTraversal1(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;

        TreeNode *current = root;
        TreeNode *lastVisited = NULL;

        while (current != NULL || !stack.empty()) {
            while (current != NULL) {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();

            if (current->right == NULL || current->right == lastVisited) {
                stack.pop();
                result.push_back(current->val);
                lastVisited = current;
                current = NULL;
            } else {
                current = current->right;
            }
        }

        return result;
    }

};