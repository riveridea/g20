/*
221. Maximal Square
https://leetcode.com/problems/maximal-square/

Given a 2D binary matrix filled with 0's and 1's, find the largest 
rectangle containing all ones and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.
*/



public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int rows = matrix.length;
        if (rows == 0)  return 0;
        int columns = matrix[0].length;
       
        int[][] lenTable = new int[rows][columns];
       
        for (int h=0; h<columns; ++h) {
            if (matrix[0][h] == '1')  lenTable[0][h] = 1;
        }
        for (int w=1; w<rows; ++w) {
            for (int h=0; h<columns; ++h) {
                if (matrix[w][h] == '0')  continue;
                lenTable[w][h] = lenTable[w-1][h] + 1;
            }
        }
        
        int maxArea = 0;
        for (int i=0; i<rows; ++i) {
            maxArea = Math.max(maxArea, maxRectangle(lenTable[i]));
        }
        return maxArea;        
    }
    
    private int maxRectangle(int[] histogram) {
        Stack<Integer> ss = new Stack<Integer>();
        int maxArea = 0, i = 0;
        while (i < histogram.length) {
            if (ss.isEmpty() || histogram[i] >= histogram[ss.peek()]) {
                ss.push(i++);
            } else {
                maxArea = Math.max(maxArea,
                        histogram[ss.pop()]*(ss.isEmpty() ? i : (i - ss.peek() - 1)));
            }
        }
        while (!ss.isEmpty()) {
                maxArea = Math.max(maxArea,
                        histogram[ss.pop()]*(ss.isEmpty() ? i : (i - ss.peek() - 1)));
        }
        return maxArea;
    }
}


# http://www.cnblogs.com/lichen782/p/leetcode_maximal_rectangle.html

