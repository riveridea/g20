/*
13. Roman to Integer
https://leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/* Java */

http://discuss.leetcode.com/questions/195/roman-to-integer

public class Solution {
    public int romanToInt(String s) {
     if(s == null || s.length() == 0){
            return 0;
        }
        int pos = s.length() - 1;
        int result = 0;
        while(pos >= 0){
            if(pos-1 >= 0 && getChar(s.charAt(pos)) > getChar(s.charAt(pos-1))){
                result += getChar(s.charAt(pos)) - getChar(s.charAt(pos-1));
                pos -= 2;
            }else{
                result += getChar(s.charAt(pos));
                pos--;
            }
        }
        return result;
    }
    
    public int getChar(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
}