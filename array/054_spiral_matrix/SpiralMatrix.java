/*
54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

public class Solution {
    public ArrayList<Integer> spiralOrder(int[][] matrix) {
        if(matrix==null || matrix.length==0 || matrix[0].length==0) return new ArrayList<Integer>();
        return spiralOrder(matrix,0,0,matrix.length,matrix[0].length);
    }
    
    
    public ArrayList<Integer> spiralOrder(int [][] matrix, int x, int y, int m, int n){
        ArrayList<Integer> res = new ArrayList<Integer>();
        if(m<=0||n<=0) return res;
        if(m==1&&n==1) {
            res.add(matrix[x][y]);
            return res;
        }
        for(int i=0;i<n-1;i++){
            res.add(matrix[x][y++]);
        }
        for(int i=0;i<m-1;i++){
            res.add(matrix[x++][y]);
        }
        if(m>1){    
            for(int i=0;i<n-1;i++){
                res.add(matrix[x][y--]);
            }
        }
        if(n>1){
            for(int i=0;i<m-1;i++){
                res.add(matrix[x--][y]);
            }
        }
        if(m==1||n==1)
            res.addAll(spiralOrder(matrix,x,y,1,1));
        else    
            res.addAll(spiralOrder(matrix,x+1,y+1,m-2,n-2));
        return res;
    }        
}