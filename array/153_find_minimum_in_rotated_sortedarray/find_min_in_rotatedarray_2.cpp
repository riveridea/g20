/*
153. Find Minimum in Rotated Sorted Array:
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

Suppose a sorted array is rotated at some pivot unknown to you 
beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
 
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
*/

#include <vector>

class Solution {

public:
    // same as finding an value in roatated array
    // need to consider the case that nums[mid] == nums[end]
    int FindMinII(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start)/2;

            if (nums[mid] < nums[end]) {
                end = mid;
            } else if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                // rule out the case: mid is same with end
                end--;
            }   
        }   

        return nums[start];
    }   

};

int main() {


}