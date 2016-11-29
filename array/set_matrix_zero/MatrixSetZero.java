/*
73 Set Matrix Zeros
https://leetcode.com/problems/set-matrix-zeroes/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/


/*
如果直接遍历整个矩阵，遇到0就把当前行当前列设为全0，那么最终会错误地将整个矩阵全变为0。
所以要先过一遍，记住哪一行应该设为全0，那一列应该设为全0，然后第二次的时候再设0。
*/

public class Solution {
    public void setZeroes(int[][] matrix) {
        // mark whether there is a ZERO at first row and first column
        boolean rowZero = false;
        boolean colZero = false;

        for (int i = 0; i < matrix.length; i++) {
        	if (matrix[i][0] == 0) {
        		colZero = true;
        		break;
        	}
        }

        
    }
}