/*
314. Binary Tree Vertical Order Traversal

Given a binary tree, return the inorder traversal of 
its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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

 #include <vector>
 #include <stack>
 #include <cstddef>

class Solution {
public:

    // recursively
    vector<int> InorderTraversal(TreeNode* root) {
        vector<int> res;

        if (root == NULL) {
            return res;
        }

        Inorder(res, root);

        return res;
    }

    void Inorder(vector<int> res, TreeNode* root) {
        if (root != NULL) {
            Inorder(res, root->left);
            res.add(root->val);
            Inorder(res, root->left);
        }
    }

    // iteratively
    vector<int> InorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> vector;

        while (true) {
            while (root != NULL) {
                stack.push(root);
                root = root->left;
            }

            if (stack.empty() == NULL) {
                break;
            }

            root = stack.pop();
            vector.add(root->val);

            root = root->right;
        }

        return vector;
    }


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

    ////////// Pre Order Traversal /////////////

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
            res.add(res->val);
            Preorder(root->right);
            Preorder(root->left);
        }
    }

    //iteratively solution
    vector<int> PreorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stack;

        while (true) {
            while (root != NULL) {
                res.add(root->val);
                stack.push(root);
                root = root->left;
            }

            if (stack.isEmpty() == true) {
                break;
            }

            root = stack.pop();
            root = root->right;
        }

        return res;
    }

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


    ////////// Post Order Traversal /////////////
    vector<int> PostorderTraversal(TreeNode* root) {
        vector<int> vector;

        if (root == NULL) {
            return vector;
        }

        Postorder(res, root);

        return vector;
    }

    void Postorder(vector<int> res, TreeNode* root) {
        if (root != NULL) {
            Postorder(root->right);
            Postorder(root->left);
            res.add(root->val);
        }
    }

    // iteratively 
    vector<int> PostorderTraversal(TreeNode* root) {
        //http://www.programcreek.com/2012/12/leetcode-solution-of-iterative-binary-tree-postorder-traversal-in-java/
    }
};

int main() {

    return 0;
}