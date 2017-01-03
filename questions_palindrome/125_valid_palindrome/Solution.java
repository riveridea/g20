/*
125. Valid Palindrome

https://leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome, considering only 
alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good 
question to ask during an interview.

For the purpose of this problem, we define empty string as valid 
palindrome.

Similar Problem:
Palindrome Linked List
*/

public class Solution {
    /*
    many corner cases are not considered
    */
    public boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
        	if (s.charAt(i++) != s.charAt(j--)) {
        		return false;
        	}
        }

        return true;
    }

    public static void main(String args[]) {
    	Solution s = new Solution();

        boolean flag = s.isPalindrome("amananama");

        if (flag) {
            System.out.println("example is a valid palindrome");
        }
    }
}