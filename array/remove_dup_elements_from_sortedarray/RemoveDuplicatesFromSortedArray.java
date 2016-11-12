/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/



// have some problem with this algorithms

/* Java */

public class Solution {
    public int removeDuplicates(int[] A) {
         int n = A.length;
        
        if (n <= 1) {
            return n;
        }

        int ptr = 0;
        int i = 1;
        
        while (i < n) {
            if (A[i] == A[ptr]) {
                i++;
            } else {
                ptr++;
                A[ptr] = A[i];
            }
        }
        
        int count = ptr+1;
        
        while (ptr < n-1) {
            A[ptr+1] = 0;
            ptr++;
        }
        
        return count;
    }
}