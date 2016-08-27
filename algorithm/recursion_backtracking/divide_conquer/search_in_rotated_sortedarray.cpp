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

        // generally speaking, either the left half or the right half 
        // of the original array is sort. We can get the conclusion by
        // comparing the mid-index-elem to the end-index-elem
     
        // assume that the array is arising-sorted

        // case 1: right half is sorted 

        
        if (nums[mid] < nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                return SearchHelper(nums, mid+1, end, target);
            } else {
                return SearchHelper(nums, start, mid-1, target);
            }
        } else {

            // A[mid] > A[end]
            // left half is sorted
            if (target >= nums[start] && target < nums[mid]) {
                return SearchHelper(nums, start, mid-1, target);
            } else {
                return SearchHelper(nums, mid+1, end, target);
            }
        }
    }


    // if list of nums is array
        /* ----------------------------------------------------*/
    // recursive method
    int Search(int A[], int n, int target) {
        return SearchInRotatedSortedArray(A, 0, n-1, target);
    }

    int SearchInRotatedSortedArray(int A[], int start, int end, int target) {
        if (start > end) {
            return -1;
        }

        int mid = start + (end-start) / 2;
        
        if (A[mid] == target) {
            return mid;
        }

        // generally speaking, either the left half or the right half 
        // of the original array is sort. We can get the conclusion by
        // comparing the mid-index-elem to the end-index-elem
     
        // assume that the array is arising-sorted

        // case 1: right half is sorted 
        if (A[mid] < A[end]) {
            // now decide which side will the target is located?
            if (target > A[mid] && target <= A[end]) {
                return SearchInRotatedSortedArray(A, mid+1, end, target);
            } else {
                return SearchInRotatedSortedArray(A, start, mid-1, target);
            }
        } else { 
            // A[mid] > A[end]
            // left half is sorted
            if (target >= A[start] && target < A[mid]) {
                return SearchInRotatedSortedArray(A, start, mid-1, target);
            } else {
                return SearchInRotatedSortedArray(A, mid+1, end, target);
            }
        }
    }

    // iterative method
    int SearchInRotatedSortedArrayI(int A[], int n, target) {
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end-start) / 2;

            if (A[mid] == target) {
                return mid;
            }

            if (A[mid] < A[end]) { // right half is sorted
                 if (target > A[mid] && target <= A[end]) {
                     start = mid + 1;
                 } else {
                     end = mid - 1;
                 }
            } else { // left half is sorted
                 if (target >= A[start] && target < A[mid]) {
                     end = mid - 1;
                 } else {
                     start = mid + 1;
                 }
            }
        }

        return -1;
    }
};