/*
7. Reverse Integer
https://leetcode.com/problems/reverse-integer/

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

###############################
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
#################################
*/


/* Java */

public class Solution {
    public int reverse(int x) {
        if(x==0)
            return 0;
    
        StringBuilder sb = new StringBuilder();
    
        if(x<0)
            sb.append("-");
    
        x=Math.abs(x);
        while(x>0){
            sb.append(x%10);
            x=x/10;
        }
    
        return Integer.valueOf(sb.toString());        
    }
}


/* C */

#include <stdio.h>

int reverseDigits(int num)
{
	int rev_num = 0;

	while (num >0) {
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}

	return rev_num;
}