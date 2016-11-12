/*
28. Implement strStr()
https://leetcode.com/problems/implement-strstr/

Implement strStr().

1a. Returns the index of the first occurrence of needle 
in haystack, or -1 if needle is not part of haystack.

1b. Returns a pointer to the first occurrence of needle in haystack, 
or null if needle is not part of haystack.
*/

/* Double Pointers */

public class Solution {
    public String strStr(String haystack, String needle) {
        
        if(needle==null){
            return haystack;
        }
 
        int start = 0;
        int index1 = 0;
        int index2 = 0; 
        
        while(index1<haystack.length() && index2<needle.length()){
            if(haystack.charAt(index1)==needle.charAt(index2)){
                index1++;
                index2++;                
            }else{
                start++;
                index1=start;
                index2=0;
 
            }
        }
        

        # index2==needle.length() && index1-start==needle.length() 
        # is duplicated.

        if(index2==needle.length()){
            return haystack.substring(start);
        }else{
            return null;
        }
    }
}