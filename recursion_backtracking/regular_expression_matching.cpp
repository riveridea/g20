/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/


public class Solution {
    public boolean isMatch(String s, String p) {
      if(s == null) return p == null;
      return m(s, p, 0, 0);       
    }
    
    
    public boolean m(String s, String p, int i, int j){
        if(j == p.length()) 
            return i == s.length();   
        if(j == p.length() - 1 || p.charAt(j + 1) != '*'){
            if(i == s.length()) 
                return false;   
            return (p.charAt(j) == '.' || s.charAt(i) == 
                    p.charAt(j)) && m(s, p, ++i, ++j);
        }
        
        while(i < s.length() && (p.charAt(j) == '.' 
                    || s.charAt(i) == p.charAt(j)))  {
                    
            if (m(s, p, i++, j + 2)) 
                return true;
        }
        
        return m(s, p, i, j + 2);   
    }
}