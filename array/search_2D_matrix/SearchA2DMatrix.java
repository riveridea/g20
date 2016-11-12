/*
74. Search a 2D Matrix
Write an efficient algorithm that searches for a value in an m x n 
matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of 
the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/


/* Java */

public class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int s = 0, e = rows*cols - 1;

        while(s<=e){
            int m = s+(e-s)/2;
            if(matrix[m/cols][m%cols]==target)
            return true;
            else if(matrix[m/cols][m%cols]>target){
                e = m -1;
            }else{
                s = m + 1;
            }
        }

        return false;        
    }
}