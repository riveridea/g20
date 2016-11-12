/*
59. Spiral Matrix II
https://leetcode.com/problems/spiral-matrix-ii/

Given an integer n, generate a square matrix filled with
elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/

public class Solution {
    public int[][] generateMatrix(int n) {
        int [][] matrix =new int[n][n];
        int start=0, end=n-1;
        int num=1;
    
        while(start<end)
        {
            for(int j=start;j<end;j++)
            {
                matrix[start][j]=num;
                num++;
            }
    
            for(int i=start;i<end;i++)
            {
                matrix[i][end]=num;
                num++;
            }
    
            for(int j=end;j>start;j--)
            {
                matrix[end][j]=num;
                num++;
            }
    
            for(int i=end;i>start;i--)
            {
                matrix[i][start]=num;
                num++;
            }
    
            start++;
            end--;
    
        }
    
        if(start==end)
        {
            matrix[start][start]=num;
        }
    
        return matrix;        
    }
}


####


public class Solution {
    public int[][] generateMatrix(int n) {
        if(n<0) return null;
        
        int[][] res = new int[n][n];
        
        int start=1, x=0, y=0;
        for(int i=n;i>0;i-=2){
            if(i==1){
                res[x][y]=start;
            }else{
                for(int j=0;j<i-1;j++){
                    res[x][y++]=start++;   
                }
                for(int j=0;j<i-1;j++){
                    res[x++][y]=start++;
                }
                for(int j=0;j<i-1;j++){
                    res[x][y--]=start++;
                }
                for(int j=0;j<i-1;j++){
                    res[x--][y]=start++;
                }
                x++;
                y++;
            }
        }
        return res;
    }
}