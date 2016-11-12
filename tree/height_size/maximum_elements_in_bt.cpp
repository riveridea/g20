/*
Give an algorithm for finding maximum element in binary tree.
*/

#include <cmath>
#include <iostream>
#include <cstddef>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int FindMax(TreeNode* root) {
    	int root_val = 0;
    	int left_val = 0;
    	int right_val = 0;
    	int max = INT_MIN;

    	if (root == NULL) {
            return 0;
    	} else {
    		root_val = root->val;
    		left_val = FindMax(root->left);
    		right_val = FindMax(root->right);

            if (left_val < right_val) {
            	max = right_val;
            } else {
            	max = left_val;
            }

            if (root_val > max) {
            	max = root_val;
            }
    	}

    	return max;
    }
};

int main(void) {
    Solution c;
    TreeNode root = TreeNode(9);
    cout << c.FindMax(&root) << endl;

	return 0;
}


 public class Solution{

 	public int findMax(TreeNode root) {
 		int max = Integer.MIN_VALUE;

 		if (root == null) {
 			return max;
 		}

 		Queue<TreeNode> q = new LinkedList<TreeNode>();
 		q.add(root);

 		while (q.isEmpty() == false) {
 			TreeNode node = q.poll();

 			if (node.left != null) {
 				q.add(node.left);
 			}

 			if (node.right != null) {
 				q.add(node.right);
 			}

 			if (max < node.val) {
 				max = node.val;
 			}
 		}

 	}
 }
 