/*
3. Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters

Given a string, find the length of the longest substring without repeating 
characters. For example, the longest substring without repeating letters 
for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest 
substring is "b", with the length of 1. Given "pwwkew", the answer is "wke", 
with the length of 3. Note that the answer must be a substring, "pwke" is 
a subsequence and not a substring.

O(n) time complexity
*/


public class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        //Map<Character,Integer> found = new HashMap<Character,Integer>();
        boolean[] flag= new boolean[256];
        
        char[] c = s.toCharArray();
        int i=0,j=0,res=0; // j start, i end

        while(i<c.length){
            if(flag[c[i]]==true){
                res=Math.max(i-j,res); 
                for(int k=j;k<i;k++){
                    if(c[k]==c[i]){
                        j=k+1;
                        break;
                    } 
                    flag[c[k]]=false;
                }
            }else
                flag[c[i]]=true;
            i++;
        }
        res=Math.max(c.length-j,res);
        return res;
    }
}

####
public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0;
        int end = 0;
        int maxLen = 0;
        boolean[] flag = new boolean[256];
        char[] c = s.toCharArray();
        int n = c.length;
        
        while (end < n) {
            if (flag[c[end]] == true) {
                maxLen = Math.max(maxLen, end-start);
                
                while (c[start] != c[end]) {
                    flag[c[start]] = false;
                    start++;
                }
                
                start++;
                end++;
                
            } else {
                flag[c[end]] = true;
                end++;
            }
        }
        
        maxLen = Math.max(maxLen, n-start);
        return maxLen;
    }
}


# reference
http://leetcode.com/2011/05/longest-substring-without-repeating-characters.html