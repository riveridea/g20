/*
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
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	//recursively
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
			Inorder(res, root->right);
		}
	}

	// iteratively



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

};

int main() {


	return 0;
}