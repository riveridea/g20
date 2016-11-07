/*
76. Minimum Window Substring
https://leetcode.com/problems/minimum-window-substring/


Given a string S and a string T, find the minimum window in S which 
will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, 
return the emtpy string "".

If there are multiple such windows, you are guaranteed that 
there will always be only one unique minimum window in S.
*/

public class Solution {
    public String minWindow(String s, String t) {
        
    }
}



-----------------------------------下面的解法是别人的思路-----------------------------------------------
双指针，动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符后，然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的
------------复杂度呢？？？？ 由于被查找的string最多也就265个字符。因此，可以把其看做是constant的， 那么，复杂度就是O(n)了 
http://leetcode0.blogspot.com/2013/09/minimum-window-substring.html
-------------------


#做法就是双指针的贪心做法，找到以i结尾的最小子串满足条件。
minn和left，right分别记录最小子串的最小值和左右位置。
data存T串的信息，now存当前i到j的信息，保存的是元素的个数。
num记录增加的元素个数是否达到条件。

http://gongxuns.blogspot.com/2012/12/import-java.html
http://leetcode0.blogspot.com/2013/09/minimum-window-substring.html
http://blog.csdn.net/havenoidea/article/details/12076127
http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html

/* Java */

Current Version

http://mattcb.blogspot.com/2012/12/minimum-window-substring.html

public class Solution {
    public String minWindow(String S, String T) {
        // Start typing your Java solution below
        // DO NOT write main() function
        char[] Tset = new char[256];
        char[] Sset = new char[256];
        for(int i = 0; i< T.length(); i++)
            Tset[T.charAt(i)]++;
        int left = 0, count =0, min =Integer.MAX_VALUE;
        String res="";
        for(int i = 0;i < S.length(); i++){
            if(Tset[S.charAt(i)] == 0) continue;
            Sset[S.charAt(i)]++;
            if(Sset[S.charAt(i)]<=Tset[S.charAt(i)]) count++;
            if(count == T.length()){
                while(Sset[S.charAt(left)]> Tset[S.charAt(left)] ||
                Tset[S.charAt(left)] ==0){
                    if(Sset[S.charAt(left)]> Tset[S.charAt(left)])
                        Sset[S.charAt(left)]--;
                    left ++;
                }
                if(min > i -left+1){
                    min = i-left+1;
                    res = S.substring(left, i+1);
                }
            }
        }
        return res;
    }
}






/* Java */
http://tianrunhe.wordpress.com/category/leetcode/

Thoughts:
The idea is from here. I try to rephrase it a little bit here. The general idea is that we find a window first, not necessarily the minimum, but it’s the first one we could find, traveling from the beginning of S. We could easily do this by keeping a count of the target characters we have found. After finding an candidate solution, we try to optimize it. We do this by going forward in S and trying to see if we could replace the first character of our candidate. If we find one, we then find a new candidate and we update our knowledge about the minimum. We keep doing this until we reach the end of S. For the giving example:

We start with our very first window: “ADOBEC”, windowSize = 6. We now have “A”:1, “B”:1, “C”:1
We skip the following character “ODE” since none of them is in our target T. We then see another “B” so we update “B”:2. Our candidate solution starts with an “A” so getting another “B” cannot make us a “trade”.
We then see another “A” so we update “A”:2. Now we have two “A”s and we know we only need 1. If we keep the new position of this “A” and disregard the old one, we could move forward of our starting position of window. We move from A->D->O->B. Can we keep moving? Yes, since we know we have 2 “B”s so we can also disregard this one. So keep moving until we hit “C”: we only have 1 “C” so we have to stop. Therefore, we have a new candidate solution, “CODEBA”. Our new map is updated to “A”:1, “B”:1, “C”:1.
We skip the next “N” and we arrive at “C”. Now we have two “C”s so we can move forward the starting position of last candidate: we move along this path C->O->D->E until we hit “B”. We only have one “B” so we have to stop. We have yet another new candidate, “BANC”.
We have hit the end of S so we just output our best candidate, which is “BANC”.


public class Solution {
   public String minWindow(String S, String T) {
        int[] needToFind = new int[256];
        int[] hasFound = new int[256];
         
        for(int i = 0; i < T.length(); ++i) {
            needToFind[T.charAt(i)]++;
        }
         
        int count = 0;
        int minWindowSize = Integer.MAX_VALUE;
        int start = 0, end = 0;
        String window = "";
         
        for(; end < S.length(); end++) {
            if(needToFind[S.charAt(end)] == 0) continue;
            char c = S.charAt(end);
            hasFound[c]++;
             
            if(hasFound[c] <= needToFind[c]) {
                count++;
            }
             
            if(count == T.length()) {
                while(needToFind[S.charAt(start)] == 0 ||
                    hasFound[S.charAt(start)] > needToFind[S.charAt(start)]) {
                    if(hasFound[S.charAt(start)] > needToFind[S.charAt(start)])
                        hasFound[S.charAt(start)]--;
                    start++;
                }
                 
                if(end - start + 1 < minWindowSize) {
                    minWindowSize = end - start + 1;
                    window = S.substring(start, end + 1);
                }
            }
        }
         
        return window;
    }
}



/* Java */
http://www.cnblogs.com/feiling/p/3301385.html

public class Solution {
    public String minWindow(String S, String T) {
        if (S == null || T == null || S.length() == 0 || T.length() == 0) {
              return "";
          }
          int[] needToFind = new int[256];
          int[] hasFound = new int[256];
  
         for (int i = 0; i < T.length(); i++) {
             needToFind[T.charAt(i)]++;
         }
 
         int minWinLen = Integer.MAX_VALUE;
         int count = 0, tLen = T.length();
         int winBeg = 0, winEnd = 0;
         for (int begin = 0, end = 0; end < S.length(); end++) {
             if (needToFind[S.charAt(end)] == 0) {
                 continue;
             }
             hasFound[S.charAt(end)]++;
             if(hasFound[S.charAt(end)] <= needToFind[S.charAt(end)]){
                 count ++;
             }
             
             if(count == tLen){
                 while(needToFind[S.charAt(begin)] == 0 ||
                         hasFound[S.charAt(begin)] > needToFind[S.charAt(begin)]){
                     if(hasFound[S.charAt(begin)] > needToFind[S.charAt(begin)]){
                         hasFound[S.charAt(begin)]--;
                     }
                     begin ++;
                 }
                 
                 int winLen = end - begin + 1;
                 if(winLen < minWinLen){
                     winBeg = begin;
                     winEnd = end;
                     minWinLen = winLen;
                 }
             }
         }
 
         if (count == T.length()) {
             return S.substring(winBeg, winEnd + 1);
         }
 
         return "";        
    }
}