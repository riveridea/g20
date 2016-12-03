/*
108. Convert Sorted Array to Binary Search Tree:
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an array where elements are sorted in ascending 
order, convert it to a height balanced BST.


1.Get the mid­dle of the array, make it as root. 
2.Take the left half of the array, call recur­sively and add it to root.left.
3.Take the right half of the array, call recur­sively and add it to root.right.
4.return root.

*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (num.size() == 0) {
            return NULL;
        }

        return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
    }
    
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, 
                                    int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        int mid = start + (end-start)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, start, mid-1);
        root->right = sortedArrayToBSTHelper(nums, mid+1, end);
        
        return root;
    }
};