/*
96. Unique Binary Search Trees
https://leetcode.com/problems/unique-binary-search-trees

Given n, how many structurally unique BST's (binary search trees) 
that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

Same Problem: Problem-48:
Give an algorithm for counting the number of BST's possible with n nodes.

Also, refer to DP folder for solution.
*/

public class Solution {
    /*
    Basic Idea:
    tree rooted as node i, its left subtree consists of [0, i-1]
    and its right subtree consists of [i+1, n]

    set dp[i] = total numbers of BST tree when there are i nodes.
    n == 0, dp[0] = 1, if empty is considered as 1 answer
    n == 1, dp[1] = 1, only one root node
    n == 2, there are two options:

        1         2
         \       /
          2     1
 
    Therefore, dp[2] = dp[0]*dp[1] + dp[1]*dp[0]
    */

    pulic int numTrees(int n) {
        int i = 0;
        int j = 0;
        int[] dp;

        dp[0] = 1;
        dp[1] = 1;

        for (i = 2; i <= n; i++) {
            dp[i] = 0;

            for (j = 0; j < i; i++) {
            	dp[i] = dp[i] + dp[j] * dp[i-j-1];
            }
        }

        return dp[n];

    }


	public static void main(String[] args) {

	}
}