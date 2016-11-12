/*
Palindrome partitioning II:

Given a string s, partition s such that every substring 
of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be 
produced using 1 cut.
*/


public class Solution {  
    public int minCut(String s) {  
        // Start typing your Java solution below  
        // DO NOT write main() function  
        int len = s.length();  
        boolean[][] matrix = createTable(s);  
        int[] min = new int[len+1];  
        min[len] = 0;  
        for(int i=len-1; i>=0; i--){  
            min[i] = len-i;  
            for(int j=i; j<len; j++)  
                if(matrix[i][j])  
                    min[i] = Math.min(min[i], 1+min[j+1]);  
        }  
          
        return min[0]-1;  
    }  
    private boolean[][] createTable(String s){  
        int len = s.length();  
        boolean[][] matrix = new boolean[len][len];  
          
        for(int i=0; i<len; i++)  
            matrix[i][i] = true;  
        for(int i=0; i<len; i++){  
            //odd  
            int m = i-1, n = i+1;  
            while(m>=0 && n<len && s.charAt(m)==s.charAt(n))  
                matrix[m--][n++] = true;  
              
            //even  
            m = i;  
            n = i+1;  
            while(m>=0 && n<len && s.charAt(m)==s.charAt(n))  
                matrix[m--][n++] = true;  
        }  
          
        return matrix;  
    }  
}  