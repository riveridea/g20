/*
20. Valid Parentheses

https://leetcode.com/problems/valid-parentheses

Given a string containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if 
the input string is valid.

The brackets must close in the correct order, 
"()" and "()[]{}" are all valid but "(]" and
 "([)]" are not.

*/

public class Solution {
    
    public boolean isLeftpart(char c) {
        if (c=='(' || c=='[' || c=='{') {
            return true;
        } else {
            return false;
        }
    }
    
    public char counterpart(char c) {
        /*
        if (c==')') {
            return '(';
        }

        if (c=='}') {
            return '{';
        }

        if (c==']') {
            return '[';
        }

        return '\0';
        */
        switch (c) {
            case ')':
                return '(';

            case '}':
                return '{';

            case ']':
                return '[';

            default:
                return '[';
        }
    }

    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<Character> buffer = new Stack<Character>();
        int ls = s.length();
        int i=0;
        boolean valid = false;

        while (i<ls) {
            char c = s.charAt(i);
            if (isLeftpart(c)) {
                buffer.push(c);
            } else {
                char chk = counterpart(c);
                if (buffer.isEmpty() || chk == '\0') 
                    return false;
                if (chk==buffer.peek()) {
                    buffer.pop();
                } else {
                    return false;
                }
            }
            i ++;
        }

        if (!buffer.isEmpty()) {
            return false;
        }
        
        return true;
    }    
    
}