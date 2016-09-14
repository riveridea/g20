/*

should be placed in algorithm/recursion_backtracking/dfs
all_root_2_leaf_paths.cpp

Binary Tree Paths:
https://leetcode.com/problems/binary-tree-paths/

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

#include <iostream>

using namespace std;

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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;

		if (root == NULL) {
			return res;
		}

		dfs(root, "", res);
		return res;
	}

	void dfs(TreeNode* root, string path, vector<string> &res) {
		path += to_string(root->val);

		if (root->left == NULL && root->right == NULL) {
			res.push_back(path);
		}

		if (root->left != NULL) {
			dfs(root->left, path + "->", res);
		}

		if (root->right != NULL) {
			dfs(root->right, path + "->", res);
		}
	}
};



/*
print_binary_tre_root_to_leaf_paths.cpp

/*
Given a binary tree, print out all of its root-to-leaf paths.
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void PrintBinaryTrePath(TreeNode* head) {

    	if (head == NULL) {
    		return NULL;
    	}

    	vector<vector<int>> paths;

    	return PrintBinaryTrePathHelper(head, paths);

    }

    void PrintBinaryTrePathHelper(TreeNode* head, 
    		vector<vector<int>>& paths, 
    		vector<int> path) {

    	path.push_back(head->val);

    	if (head->left==NULL && head->right==NULL) {
    		return;
    	} else {
    		if (head->left != NULL) {
    			PrintBinaryTrePathHelper(node->left, paths, path);
    		}

    		if (head->right != NULL) {
    			PrintBinaryTrePathHelper(node->right, paths, path);
    		}
    	}

    	paths.pop_back();
    }

};



public static void paths(Node node, LinkedList<Integer> list) { 
if(node == null) return; 
list.add(node.data); 

if(node.left == null && node.right == null) { 
print(list); 
return;
} 
else { 
paths(node.left, list); 
paths(node.right, list); 
} 
} 

public static void print(LinkedList<Integer> list) { 
System.out.println("Contents of list: " + list); 
} 


public void Wrapper(Node root)
{
    PrintAllPaths(root, "");
}

public void PrintAllPaths(Node node, string pathSoFar)
{
    if(node==null)
    {
        Console.WriteLine(pathSoFar);
        return;
    }
    PrintAllPaths(node.left, pathSoFar + ", " node.data);
    PrintAllPaths(node.right, pathSoFar + ", " node.data);
}