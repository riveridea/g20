/*
Rotate Image:
https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

// 矩阵顺时针转90度：先沿中线水平翻转，再沿着对角线翻转  
// eg:

    
            1 2 3         7 8 9       7 4 1 
            4 5 6   =>    4 5 6   =>  8 5 2 
            7 8 9         1 2 3       9 6 3 
// 或者一圈一圈转       

*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();

        for (int layer = 0; layer < length/2; layer++) {
        	int start = layer;
        	int end = length - 1 - layer; // index attention

        	for (int i = start; i < end; i++) {
        		int offset = i - start;
        		// save the top line
        		int tmp = matrix[start][i];

        		// left to top
        		matrix[start][i] = matrix[end-offset][start];

        		// bottom to left
        		matrix[end-offset][start] = matrix[end][end-offset];

        		// right to bottom
        		matrix[end][end-offset] = matrix[i][end-offset];

        		// top to right
        		matrix[i][end-offset] = tmp;

        	}
        }
    }
};