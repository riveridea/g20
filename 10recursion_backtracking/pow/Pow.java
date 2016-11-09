/*
50. Pow(x, n)
https://leetcode.com/problems/powx-n/

Implement pow(x, n).
*/

public class Solution {
    public double myPow(double x, int n) {
        if(n == 0) {
        	return 1;
        }

        if(x == 0) {
        	return 0;
        }

        if(n>0) {
        	return 1.0/myPow(x,-n);
        } else{
            double s=myPow(x,n/2);
            
            if(n%2 != 0) {
            	return s*s/x;
            } else {
            	return s*s;
            }
        }       
    }
}