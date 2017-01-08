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

/*
google 面试第五版 1.7.txt
asked by Zinga:
*/

class Solution {

	// O(m+n) space
    public void setZeroes(int[][] matrix) {
        //
        int row = matrix.length;
        int column = matrix[0].length;

        int[] rowFlags = new int[row];
        int[] columnFlags = new int[column];

        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < column; j++) {
        		if (matrix[i][j] == 0) {
        			rowFlags[i] = 1;
        			columnFlags[j] = 1;
        		}
        	}
        }

        for (int i = 0; i < row; i++) {
        	for (int j = 0; j < column; j++) {
        		if (rowFlags[i] == 1 || columnFlags[j] == 1) {
                    matrix[i][j] = 0;
        		}
        	}
        }
    }

    public void printMatrix(int[][] matrix) {
        int row = matrix.length;
        int column = matrix[0].length;

        system.out.print("{");
    	for (int i = 0; i < row; i++) {

    		system.out.print("{");

    		for (int j = 0; j < column; j++) {
    			system.out.print(matrix[i][j]);
    		}

    		system.out.print("{");
    		system.out.println();
    	}
    }
}

public class MatrixSetZero {


	public static void main(String[] args) {
    	int[][] matrix = {{0,0,0,5},
                          {4,3,1,4},
                          {0,1,1,4},
                          {1,2,1,3},
                          {0,0,1,1}};
    }
}