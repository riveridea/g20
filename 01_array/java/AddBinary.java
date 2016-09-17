/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


/* My Solution follows the Two Pointer Strategy */

public class Solution {
    public String addBinary(String a, String b) {
        if(a == null || b == null) {
            return null;
        }
        
        int m = a.length();
        int n = b.length();
        
        if(m == 0 || n == 0) {
            return null;
        }
        
        int carry = 0;
        String string = "";
        
        while ( m>0 || n>0 ) {
            
            int sa = 0;
            int sb = 0;
            
            if (m>0) {
                sa = a.charAt(m-1) - '0';
            }
            
            if (n>0) {
                sb = b.charAt(n-1) - '0';
            }
            
            int temp = carry + sa + sb;
            string = temp % 2 + string;
            carry = temp/2;
            
            m--;
            n--;
        }
        
        return (carry==0)? string: "1" + string;
    }
}