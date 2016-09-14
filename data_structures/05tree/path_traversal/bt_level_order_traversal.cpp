/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of 
its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,null,null,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) {
        	return result;
        }

        queue<TreeNode*> queue;
        queue.add(root);
        int levelSize = queue.size();

        while (queue.empty() == false) {
        	int index = 0;
        	vector<int> currentLevel = NULL;

        	while (index < levelSize) {
        		TreeNode* node = queue.front();

        		if (node->left != NULL) {
        			queue.push(node->left);
        		}

        		if (node->right != NULL) {
        			queue.push(node->right);
        		}

        		currentLevel.push_back(node->val);
        		queue.pop();
        		index++;
        	}

        	res.push_back(currentLevel);
        	levelSize = queue.size();
        }

        return result;
    }


    vector<vector<int>> levelOrder2(TreeNode* root) {
    	vector<vector<int>> result;

    	if (root == NULL) {
    		return result;
    	}

    	queue<TreeNode*> queue;
    	queue.add(root);

    	int levelSize =1;

    	while (queue.empty() != true) {
    		int count = 0;
    		vector<int> currentLevel = NULL;

    		for (int i = 0; i < levelSize; i++) {
    			TreeNode* node = queue.front();
    			currentLevel.push_back(node->val);

    			if (node->left != NULL) {
    				queue.push_back(node->left);
    				count++;
    			}

    			if (node->right != NULL) {
    				queue.push_back(node->right);
    				count++;
    			}
    		}

    		result.push_back(currentLevel);
    		levelSize = count;
    	}

        return result;
    }
};