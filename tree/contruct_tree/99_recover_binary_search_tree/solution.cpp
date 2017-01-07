/*
99. Recover Binary Search Tree:
https://leetcode.com/problems/recover-binary-search-tree/

Two elements of a binary search tree (BST) are 
swapped by mistake. Recover the tree without 
changing its structure.

Note:
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?

confused what "{1,#,2,3}" 
OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order
traversal, where '#' signifies a path terminator where 
no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    void recoverTree(TreeNode* root) {
        
    }



public class Solution {
    ArrayList<TreeNode> t;
    TreeNode previous;

    public void recoverTree(TreeNode root) {

        t = new ArrayList<TreeNode>();
        previous=null;
        inorder(root);
        int temp = t.get(0).val;
        t.get(0).val = t.get(t.size()-1).val;
        t.get(t.size()-1).val = temp;
    }

    public void inorder(TreeNode root) {
        if(root==null) 
            return;
        inorder(root.left);

        if(previous!=null&&previous.val>root.val) {
            if(!t.contains(previous)) 
                t.add(previous);
            if(!t.contains(root)) 
                t.add(root);
        }

        previous = root;
        inorder(root.right);
    }
}



    // with Space O(n), in order travelse
    // then reassign the values.
    void recoverTree(TreeNode* root) {
    	vector<TreeNode*> list;
    	vector<int> vals;

    	InOrderTravel(root, list, vals);

    	sort(vals.begin(), vals.end());

    	for (int i = 0; i<list.size(); i++) {
    		list[i]->val = vals[i];
    	}
    }

    void InOrderTravel(TreeNode* node, 
    		vector<TreeNode *>& list, 
    		vector<int>& vals) {
    	if (node == NULL) {
    		return;
    	}

    	InOrderTravel(node->left, list, vals);
    	list.push_back(node);
    	vals.push_back(node->val);
    	InOrderTravel(node->right, list, vals);
    }
};