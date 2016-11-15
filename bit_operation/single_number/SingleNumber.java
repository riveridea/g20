/*
136. Single Number
https://leetcode.com/problems/single-number/

Given an array of integers, every element appears twice 
except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
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