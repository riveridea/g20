/*
72. Edit Distance
https://leetcode.com/problems/edit-distance/

Given two words word1 and word2, find the minimum number of steps 
required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/



/* Java */

public class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length(), n = word2.length();
        int[][] distances = new int[m+1][n+1];
        distances[0][0] = 0;
        for(int i=1;i<=m;i++)
            distances[i][0]=i;
        for(int i=1;i<=n;i++)
            distances[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1))
                    distances[i][j] = distances[i-1][j-1];
                else
                    distances[i][j] = 1+Math.min(distances[i-1][j-1],Math.min(distances[i-1][j],distances[i][j-1]));
            }
        }
        return distances[m][n];       
    }
}