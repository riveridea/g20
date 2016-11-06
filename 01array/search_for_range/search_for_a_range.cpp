/*
https://leetcode.com/problems/search-for-a-range

Given a sorted array of integers, find the starting and ending 
position of a given target value. Your algorithm's runtime complexity 
must be in the order of O(log n). If the target is not found in 
the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

//两次 binary search， 一次找比target大一个的，一次找比target小一个的

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> range(2, -1);
        int lower = 0;
        int upper = nums.size();
        int mid;

        // Search for lower bound
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (nums[mid] < target)
                lower = mid + 1;
            else
                upper = mid;
        }

        // If the target is not found, return (-1, -1)
        if (nums[lower] != target)
            return range;
        range[0] = lower;

        // Search for upper bound
        upper = nums.size();
        
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (nums[mid] > target)
                upper = mid;
            else
                lower = mid + 1;
        }
        range[1] = upper - 1;

        return range;
    }
};