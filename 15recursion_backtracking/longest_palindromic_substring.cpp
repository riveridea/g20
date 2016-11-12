/*
https://leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S. You 
may assume that the maximum length of S is 1000, and there exists 
one unique longest palindromic substring.

similar issues:
1. shortest palindrome
2. palindrome permutation
3. palindrome pairs
*/

class Solution {

public:

    // 1. Dynamic Programming
    /*
     * Let s be the input string, i and j are two indices of the string. 
     * Define a 2-dimension array "table" and let table[i][j] denote 
     * whether a substring from i to j is palindrome.
     *
     * Formular:
     * table[i+1][j-1] == 1, assume that substring from index i+1 to index
     * j-1 is a palindrome/
     * table [i][j] = (s[i] == s[j]) && table[i+1][j-1]
     * 
     * Time: O(n^2)
     * Space: O(n^2)
     *   
     */
    string longestPalindrome(string s) {
    
    
    // 2. straightforward method    
    
    }

};
