/* Given an array and a value, remove all instances of that 
value in place and return the new length.

The order of elements can be changed. It doesn't matter 
what you leave beyond the new length.
*/


/* Java */

public class Solution {
    public int removeElement(int[] A, int elem) {
        int len = A.length;
        int i = 0;
        
        while (i < len) {
            if (A[i] == elem) {
                A[i] = A[--len];
            } else {
                i++;
            }
        }
        
        return len;
    }
}