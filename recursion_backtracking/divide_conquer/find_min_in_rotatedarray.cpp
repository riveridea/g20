/*
153. Find Minimum in Rotated Sorted Array:
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

Suppose a sorted array is rotated at some pivot unknown to you 
beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element. You may assume no duplicate exists 
in the array.
*/

/*
同样可以根据A[mid]和A[end]来判断右半数组是否sorted：
原数组：0 1 2 4 5 6 7
情况1：  6 7 0 1 2 4 5   
情况2：  2 4 5 6 7 0 1  
(1) A[mid] < A[end]：A[mid : end] sorted => min不在A[mid+1 : end]中
搜索A[start : mid]
(2) A[mid] > A[end]：A[start : mid] sorted且又因为该情况下
A[end]<A[start] => min不在A[start : mid]中
搜索A[mid+1 : end]
(3) base case：
a. start =  end，必然A[start]为min，为搜寻结束条件。
b. start + 1 = end，此时A[mid] =  A[start]，
而min = min(A[mid], A[end])。而这个条件可以合并到(1)和(2)中。
*/


#include <vector>

class Solution {

public:

    int FindMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start)/2;

            if (nums[mid] < nums[end]) {
                // then left side is sorted, min element
                // should appear in the right side
                end = mid;
            } else {
                // then right side is sorted, min element
                // should appear in the left side.
                start = mid + 1;
            }   
        }   

        return nums[start];
    }

};

int main() {


}
