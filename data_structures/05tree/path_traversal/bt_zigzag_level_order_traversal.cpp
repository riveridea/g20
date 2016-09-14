/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> results;
        
        if (root == NULL) {
            return results;
        }
        
        stack<TreeNode*> curLevel;
        stack<TreeNode*> nextLevel;
        
        curLevel.push(root);
        
        bool left2right = true;
        
        while(!curLevel.empty()) {
            vector<int> curLevelValues;
            
            while (!curLevel.empty()) {
                TreeNode* tmp = curLevel.top();
                curLevel.pop();
                curLevelValues.push_back(tmp->val);
            
                if (left2right) {
                    if (tmp->left) {
                        nextLevel.push(tmp->left);
                    }
                    if (tmp->right) {
                        nextLevel.push(tmp->right);
                    }
                } else {
                     if (tmp->right) {
                        nextLevel.push(tmp->right);
                    }
                    if (tmp->left) {
                        nextLevel.push(tmp->left);
                    }
                }
            } // done with one level
            
            //save a level
            results.push_back(curLevelValues);
            
            // swap curLevel and nextLevel
            swap(curLevel, nextLevel);
            
            left2right = !left2right;
        }
        
        return results;
    }
};