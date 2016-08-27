/*
Leetcode: https://leetcode.com/problems/search-in-rotated-sorted-array

Suppose a sorted array is rotated at some pivot unknown to you 
beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array 
return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return SearchHelper(nums, 0, nums.size()-1, target);
    }
    
    int SearchHelper(vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;    
        }
        
        int mid = start + (end-start)/2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        if (nums[mid] < nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                return SearchHelper(nums, mid+1, end, target);
            } else {
                return SearchHelper(nums, start, mid-1, target);
            }
        } else {
            if (target >= nums[start] && target < nums[mid]) {
                return SearchHelper(nums, start, mid-1, target);
            } else {
                return SearchHelper(nums, mid+1, end, target);
            }
        }
    }
};