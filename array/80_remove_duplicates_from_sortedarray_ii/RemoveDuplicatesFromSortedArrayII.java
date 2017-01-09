/*  Need more time
80. Remove Duplicates from Sorted Array II
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/

/* Java */

public class Solution {
    public int removeDuplicates(int[] A) {
    
    int length = A.length;
    
    if(length < 3) 
        return length;
        
    int i = 1, cur = 1;

    for(int j = 1; j < length; j++){
        if(A[j] == A[j-1]){
            cur++;
        }else{
            cur = 1;
        }
        
        if(cur <= 2){
            A[i] = A[j];
            i++;
        }
    }

    int size = i;
    
    while (i < length) {
        A[i++] = 0;
    }

    return size;
    
    }
}