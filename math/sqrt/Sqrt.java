/*
69. Sqrt(x)
https://leetcode.com/problems/sqrtx/

Implement int sqrt(int x).
Compute and return the square root of x.
*/

public class Solution {
    public int mySqrt(int x) {
        long low = 0, high = x;
        long mid;
        while(low <= high){
            mid = (low+high)/2;
            if(mid*mid == x) return (int)mid;
            else if(mid*mid < x) low = mid+1;
            else high = mid-1;
        }
        mid = (low+high)/2;
        return (int)mid;        
    }
}