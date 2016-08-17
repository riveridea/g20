/*
Sort Colors:
https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them 
so that objects of the same color are adjacent, with the colors in 
the order red, white and blue. Here, we will use the integers 0, 1,
 and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting 
sort. First, iterate the array counting number of 0's, 1's, and 2's, then
overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/


// 两边往中间走，是红的放左边，是蓝的放右边

#include <iostream>

using namespace std;

class Solution {
public:
    // red 0; white 1; blue 2
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() -1;
        
        int i = 0;
        
        while (i <= right) {
            if (nums[i]== 0) {
                swap(nums[i++], nums[left++]);
            } else if (nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[right--]);
            }
        }
    }

    void swap (int& num1, int& num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
};

int main() {
    vector<int> unSortedArrayOfColors = {2, 1, 0, 0, 2, 1};

    Solution solution1;
    cout << "new length is: " + solution1.sortColors(unSortedArrayOfColors) << endl;

    return 0;
}
