/*
Find the contiguous subarray within an array 
(containing at least one number) which has the 
largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest 
sum = 6.
*/

/* Java */

public class Solution {
    public int maxSubArray(int[] A) {
        int sum = Integer.MIN_VALUE;
        int tmp = 0;
        
        for (int i = 0; i < A.length; i++) {
            if (tmp <= 0) {
                tmp = A[i];
            } else {
                tmp = tmp + A[i];
            }
            
            if (sum < tmp) {
                sum = tmp;
            }
        }
        
        return sum;
    }
}