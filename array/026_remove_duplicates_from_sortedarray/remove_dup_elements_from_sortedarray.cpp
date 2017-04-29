#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/*

	Remove Duplicates from Sorted Array:
	https://leetcode.com/problems/remove-duplicates-from-sorted-array/
	
Given a sorted array, remove the duplicates in place such that 
each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this 
in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2] respectively.
It doesn't matter what you leave beyond the new length..
*/
    int removeDuplicates1(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return n;
        }
        
        int index = 0;
        int start = 1;
        
        while (start < n) {
            if (nums[start] == nums[index]) {
                start++;
            } else {
                index++;
                nums[index] = nums[start];
            }
        }
        
        int count = index +1;
        
        while (index < n) {
            nums[index] = 0;
            index++;
        }
        
        return count;
    }

};

int main() {
	vector<int> nums = {1, 1};
	Solution s;
	cout << "{1, 1} result is: " <<  s.removeDuplicates1(nums) << endl;
	return 0;
}