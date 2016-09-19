/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

/* Java */
public class Solution {
    public int singleNumber(int[] A) {
            int i;
            int result = 0;
        
            for (i = 0; i < A.length; i++)
                result ^= A[i];
        
            return result;        
    }
}