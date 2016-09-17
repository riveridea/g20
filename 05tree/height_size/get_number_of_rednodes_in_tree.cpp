/*
write the function to find the total number of tree
node that has the color 'RED'
*/

/*
 *
 */

#include <cstddef>
#include <iostream>

using namespace std;

enum Color {
    red,
    green,
    blue
};

struct TreeNode {
    Color color;
    TreeNode *left;
    TreeNode *right;
    TreeNode(Color x): color(x), left(NULL), right(NULL) {}
};



class Solution {
public:
 	int ReturnRedNodeNumber(TreeNode* root) {
 		if (root == NULL) {
 			return 0;
 		} else {
 			return ReturnRedNodeNumber(root->left) +
 		        ReturnRedNodeNumber(root->right) +
 		        ((root->color  == red)? 1: 0);
 		}
 	}

};

int main(void) {
    Solution s;
    Color rootColor = red;
    TreeNode root = TreeNode(rootColor);

    cout << "The number of red nodes is: " << s.ReturnRedNodeNumber(&root) << endl;
    return 0;
}