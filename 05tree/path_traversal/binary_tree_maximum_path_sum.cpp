/*
Binary Tree Maximum Path Sum:
https://leetcode.com/problems/binary-tree-maximum-path-sum/

Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the 
parent-child connections. The path does not need to go 
through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
 
/*
4. 所以这里可以采用bottom-up的递归方法:
对于节点x:
定义PS1(x)为从x出发向leaf方向的第一类path中最大的path sum。
定义PS2(x)为以x为LCA的第二类path中的最大path sum。
显然如果我们求得所有节点x的PS1 & PS2，其中的最大值必然就是要求的max path sum。

5. 如何求PS1(x)、PS2(x)?
(1) PS1(x) 、PS2(x)至少应该不小于x->val，因为x自己就可以作为一个单节点path。
(2) PS1(x) 、 PS2(x)可以从PS1(x->left)和PS1(x->right)来求得：
PS1(x) = max [ max(PS1(x->left), 0), max(PS1(x->right), 0) ] + x->val
PS2(x) = max(PS1(x->left), 0) + max(PS1(x->right), 0) + x->val
注意这里并不需要PS2(x->left) 以及 PS2(x->right) 因为子节点的2型path无法和父节点构成新的path。

6. 需要返回PS1(x)以供上层的节点计算其PS1 & PS2.

7. 对于leaf节点：PS1(x) = PS2(x) = x->val.


*/

class Solution {
public:

    // for each node, there are four possibilies way
    // to get max path:
    // 1. Node only
    // 2. L-sub + Node
    // 3. R-sub + Node
    // 4. L-sub + Node + R-sub
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        int ps1_root = findMaxPathSum(root, maxSum);
        return maxSum;
    }
    
    int findMaxPathSum(TreeNode *root, int &maxSum) {
        if(!root) return 0;
        
        int ps1_left = 0, ps1_right = 0;
        if(root->left) 
            ps1_left = max(findMaxPathSum(root->left,maxSum),0);
        if(root->right)
            ps1_right = max(findMaxPathSum(root->right,maxSum),0);
        
        int ps1_root = max(ps1_left, ps1_right) + root->val;    
        int ps2_root = ps1_left + ps1_right + root->val;
        maxSum = max(maxSum,max(ps1_root, ps2_root));
        
        return ps1_root;
    }
};