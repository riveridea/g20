/*
Search In Rotated SortedArray II:
Leetcode: https://leetcode.com/problems/search-in-rotated-sorted-array-ii

Suppose a sorted array is rotated at some pivot unknown to you
beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array 
return its index, otherwise return -1. 

What if duplicates are allowed?
Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start <= end) {
            int mid = start + (end-start)/2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[mid] < nums[end]) {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (nums[mid] > nums[end]) {
                if (target < nums[mid] && target >= nums[start]) {
                    end = mid -1;
                } else {
                    start = mid + 1;
                }
            // if nums[mid] == nums[end], then we cannot come to the 
            // the conclusion that either left or right side of the 
            // arrary is sorted. Instead, we can exclude the last element
            // namely, nums[end]. So, the worst case, time complexity is
            // O(n)     
            } else {
                // mid is equal to the end
                end --;
            }
        }
        
        return false;
    }
};