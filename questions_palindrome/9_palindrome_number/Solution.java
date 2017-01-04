/*
9. Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space.

https://leetcode.com/problems/palindrome-number/

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction 
of using extra space. You could also try reversing an integer. However, if you 
have solved the problem "Reverse Integer", you know that the reversed integer 
might overflow. How would you handle such case?

There is a more generic way of solving this problem.

http://leetcode.com/2012/01/palindrome-number.html
*/


public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        int division = 1;
        
        while (x / division >= 10) {
            division *= 10;
        }
        
        while (x != 0) {
            int left = x /division;
            int right = x % 10;
            
            if (left != right) 
                return false;
                
            x = (x % division) / 10;  // it is wrong to put 10 here.
            
            division /= 100;
        }
        
        return true;
    }
}



// not pass 121 case
public class Solution {
    public boolean isPalindrome(int x) {
        return isPalindromeHelper(x, x);
    }
    
    public boolean isPalindromeHelper(int x, int y) {
        if (x < 0) {
            return false;
        }
        
        if (x == 0) {
            return true;
        }
        
        if (isPalindromeHelper(x/10, y) && (x%10 == y%10)) {
            y /= 10;
            return true;
        } else {
            return false;
        }
    }
}