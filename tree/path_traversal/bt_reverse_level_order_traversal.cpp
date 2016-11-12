/*
Binary Tree Level Order Traversal II

https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
Given a binary tree, return the bottom-up level order traversal of 
its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]
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

/*
The basic idea is still traversing the binary tree in level order 
(up-down). We can just use a vector to store the nodes and its level, 
set a pointer, each time move forward one and push its children into
the vector. When all the nodes are visited, the vector become the
up-down nodes in level order with level information
*/
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (!root) {return vector<vector<int> >();}
        vector<pair<TreeNode*,int> > q;
        int lev=1;
        int count=0;
        q.push_back(make_pair(root,lev));
         
        while (count<q.size()){
            TreeNode *node = q[count].first;
            lev = q[count].second;
            if (node->left){ q.push_back(make_pair(node->left,lev+1));}
            if (node->right){ q.push_back(make_pair(node->right,lev+1));}
            count++;
        }
         
        vector<vector<int> > res(lev, vector<int>());
        
        // output the result
        for (int i=0;i<q.size();i++){
            res[lev-q[i].second].push_back(q[i].first->val);
        }
         
        return res;
    }
};

//OR


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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        
        if (root == NULL) {
            return res;
        }
        
        queue<TreeNode*> queue;
        queue.push(root);
        int size = queue.size();
        
        while (size > 0) {
            int index = 0;
            vector<int> valuesInLevel;
            
            while (index<size) {
                TreeNode* current = queue.front();
                queue.pop();
                
                if (current->left != NULL) {
                    queue.push(current->left);
                }
                
                if (current->right != NULL) {
                    queue.push(current->right);
                }
                
                valuesInLevel.push_back(current->val);
                index++;
            }
            
            // take advantage of datastructure. 
            res.insert(res.begin(), valuesInLevel);
            size = queue.size();
        }
        
        return res;
    }
};

