/*
287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number

Given an array nums containing n + 1 integers where each 
integer is between 1 and n (inclusive), prove that at least 
one duplicate number must exist. Assume that there is only 
one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could 
be repeated more than once.
*/

/*
Ideas:
1.  Hash,  time:O(n) space O(n). adding extra space
2.  Brute force, time:(n^2) space O(1)
3.  Sorting, time: O(nlongn) space O(1). will modify original space
4.  divide-conquer: time: O(nlogn), space O(1) or Pigeonhole priciple
*/


public class Solution {
    public int findDuplicate(int[] nums) {
        int min = 0;
        int max = nums.length - 1;

        while (min <= max) {
        	int mid = (max + min)/2;
        	int count = 0;

        	// get how many numbers in array smaller than
        	// index mid
        	for (int i = 0; i < nums.length; i++) {
        		if (nums[i] <= mid) {
        			count++;
        		}
        	}

        	if (count > mid) {
        		max = mid - 1; // duplicate occurs in first part of array
        	} else {
        		min = mid + 1; // in the second part of array
        	}
        }

        return min;
    }

    // use fast, slow index
    public int findDuplicate1(int[] nums) {
        int slow = 0;
        int fast = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // start from index 0
        int find = 0;

        while (find != slow) {
            slow = nums[slow];
            find = nums[find];
        }

        return find;
    }
}