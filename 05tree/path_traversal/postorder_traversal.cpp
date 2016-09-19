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
    /* alogrithm from wiki
	iterativePostorder(node)
  		s ← empty stack
  		lastNodeVisited ← null
  		while (not s.isEmpty() or node ≠ null)
    	    if (node ≠ null)
                s.push(node)
                node ← node.left
            else
                peekNode ← s.peek()
                // if right child exists and traversing node
                // from left child, then move right
                if (peekNode.right ≠ null and lastNodeVisited ≠ peekNode.right)
                    node ← peekNode.right
                else
                    visit(peekNode)
                    lastNodeVisited ← s.pop()
    */
                    
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* lastNodeVisited = NULL;
        vector<int> result;
        TreeNode* node = root;
        TreeNode* peekNode = NULL;
        
        while (!stack.empty() || node != NULL) {
            if (node != NULL) {
                stack.push(node);
                node = node->left;
            } else {
                peekNode = stack.top();
                
                if (peekNode->right != NULL && lastNodeVisited != peekNode->right) {
                    node = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastNodeVisited = stack.top();
                    stack.pop();
                }
            }
        }
        
        return result;
    }
};
