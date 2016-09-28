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

public class Solution {
    // tested in leetcode, passed
    // straightforward method
    // Time: O(n^2)
    // Space: O(1)
    public String longestPalindrome(String s) {  
        // Start typing your Java solution below  
        // DO NOT write main() function  
        String res = "";  
        String tmp = "";  

        // 从左往右遍历string，每一个字符都由里向外检测
        // 其回文可能性及其长度，返回两种（奇偶）回文，
        // 取最大值，遍历完成后，最长回文substring自然得出。       
        for(int i=0; i<s.length(); i++){  
            tmp = getPalindrome(s, i, i);  
            if(tmp.length() > res.length())  
                res = tmp;  
              
            tmp = getPalindrome(s, i, i+1);  
            if(tmp.length() > res.length())  
                res = tmp;  
        }  
          
        return res;  
    }  
      
    private String getPalindrome(String s, int left, int right){  
        while(left >= 0 && right < s.length() && 
                s.charAt(left) == s.charAt(right)){  
            left--;  
            right++;  
        }
  
        return s.substring(left+1, right);  
    }  
}
