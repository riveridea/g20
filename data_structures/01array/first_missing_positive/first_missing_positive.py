/*
 First Missing Positive:

 https://leetcode.com/problems/first-missing-positive/
 * 
 * Given an unsorted integer array, to find the first 
 * missing positive integer.
 * For exmaple, 
 *   Given [1, 2, 0], return 3;
 *   and [3, 4, -1, 1], return 2. // program outputs 1 ??          
 *
 * Your algorithm should run in O(n) time and use constant space.
 */

class Solution {
public:
    // 无序数组的题目如果要O(n)解法往往要用到hash table，
    // 但这题要求constant space。所以可以用数组本身作为
    // 一个"hash table"：A[0] = 1, A[1] = 2, .... A[n-1] 
    // = n。目标是尽可能将数字i放到数组第i-1个位置。
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        int i = 0;
        
        // 桶排序
        while (i < length) {
            /*
            1. 如果A[i]<1或者A[i]>n。说明A[i]一定不是first missing positive。跳过
            2. 如果A[i] = i+1，说明A[i]已经在正确的位置，跳过
            3. 如果A[i]!=i+1，且0<A[i]<=n，应当将A[i]放到A[A[i]-1]的位置，所以可以交换两数。
            4. 这里注意，当A[i] = A[A[i]-1]时会陷入死循环。这种情况下直接跳过。
            */
            if (nums[i] > 0 && nums[i] <= length
                    && nums[i] != i+1 && nums[i] != nums[nums[i] -1]) {
               swap(nums[i], nums[nums[i]-1]);
            } else {
                i++;
            }
        }
        
        for (int j = 0; j < length; j++) {
            if (nums[j] != j+1) {
                return j+1;
            }
        }
        
        // 如果当前数组找不到目标值的话，
        // 那么目标值就应该是n+1。
        return length+1;
        
    }
};