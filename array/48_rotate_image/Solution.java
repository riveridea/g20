/*
48. Rotate Image
https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

    // 矩阵顺时针转90度：先沿中线水平翻转，再沿着对角线翻转  
    // eg:   
    /* 
            1 2 3         7 8 9       7 4 1 
            4 5 6   =>    4 5 6   =>  8 5 2 
            7 8 9         1 2 3       9 6 3 
     */  

public class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;  
          
        // 先沿中线水平翻转  
        for(int i=0; i<len/2; i++){  
            for(int j=0; j<len; j++){  
                int tmp = matrix[i][j];  
                matrix[i][j] = matrix[len-1-i][j];  
                matrix[len-1-i][j] = tmp;  
            }  
        }  
        
        // 再沿着对角线翻转  
        for(int i=0; i<len; i++){  
            for(int j=i+1; j<len; j++){  
                int tmp = matrix[i][j];  
                matrix[i][j] = matrix[j][i];  
                matrix[j][i] = tmp;  
            }  
        }  
    }
}

// 或者一圈一圈转       

// Answer from CC150

public class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;

        for (int layer = 0; layer < len/2; layer++) {
            int start = layer;
            int end = len - 1 - layer;

            for (int i = start; i < end; i++) {
                int offset = i - start;
                // save the top line
                int tmp = matrix[start][i];

                // left to top
                matrix[start][i] = matrix[end-offset][start];

                //bottom to left
                matrix[end-offset][start] = matrix[end][end-offset];

                //right to bottom
                matrix[end][end-offset] = matrix[i][end];

                //top to right
                matrix[i][end] = tmp;

            }
        }

    }

}