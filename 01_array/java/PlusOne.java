/*
Given a number represented as an array of digits, plus one to the
number.
*/

# 从数组尾部到头部处理，用一个overflow flag来判断是否溢出，如果溢出则需要新开一个array

/* Java */

public class Solution {
    public int[] plusOne(int[] digits) {
        boolean overflow = false;
        int i = digits.length - 1;
        
        digits[i] += 1;
        
        while (digits[i] >= 10) {
            digits[i] -= 10;
            i--;
            
            if (i >= 0) {
                digits[i] +=1;
            } else {
                overflow = true;
                break;
            }
        }
        
        if (carry == false) {
            return digits;
        }
        
        int[] res = new int[digits.length + 1];
        
        for (i = 0; i < digits.length; i++) {
            res[i+1] = digits[i];
        }
        
        res[0] = 1;
        
        return res;
    }
}