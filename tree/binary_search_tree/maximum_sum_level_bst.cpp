/*
Give an algorithm for finding the level which is having 
maximum sum in the binary tree.
*/

class Solution {

public:
	int findLevelWithMaxSum(TreeNode* root) {

		if (root == NULL) {
			return NULL;
		}

		int level = 0;
		int maxValueLevel = 0;

		queue<TreeNode*> q;
		int currentSum = 0;
		int maxSum = 0;

		TreeNode* temp = NULL;

		q.push(root);
		q.add(NULL);

		// 其实可以加一个计数器

		while (q.empty() != true) {
			temp = q.front();
			q.pop();

			if (temp != NULL) {
				currentSum += temp->val;

				if (temp->left != NULL) {
					q.push(temp->left);
				}

				if (temp->right != NULL) {
					q.push(temp->right);
				}	
			} else {
				// done with a level
				if (currentSum > maxSum) {
					maxSum = currentSum;
					maxLevel = level;
				}

				currentSum = 0;

				if (q.empty() == fale) {
					q.push(NULL);
				}
				level++;
			}
		}

		return maxValueLevel;

	}
};