/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/


大家首先看，这个解法里面的stack，不是用来存左右括号的。人是来存左括号的index。本来么，右括号也不用存。遍历S。遇到'('，放入lefts。如果遇到')'，如果lefts是空，说明这是一个无法匹配的')'，记录下last。last里面存放的其实是最后一个无法匹配的')'。为啥要保存这个值呢？主要是为了计算后面完整的表达式的长度。可以这样理解： “所有无法匹配的')'”的index其实都是各个group的分界点。


public class Solution {
    public int longestValidParentheses(String s) {
        int maxLen = 0, last = -1;
          Stack<Integer> lefts = new Stack<Integer>();
          for (int i=0; i<s.length(); ++i) {
              if (s.charAt(i)=='(') {
                  lefts.push(i);
              } else {
                  if (lefts.isEmpty()) {
                      // no matching left
                     last = i;
                 } else {
                     // find a matching pair
                     lefts.pop();
                     if (lefts.isEmpty()) {//有一个完整的valid的group。计算该group的长度
                         maxLen = Math.max(maxLen, i-last);
                     } else {
                        //栈内还有‘(',一个最外层完整的group还没有匹配完成，
                         //但是通过查询下一个即将匹配还未匹配的"("的index来更新maxLen。
                         maxLen = Math.max(maxLen, i-lefts.peek());
                     }
                 }
             }
         }
         return maxLen;       
    }
}


###########

public class Solution {
    public int longestValidParentheses(String s) {
        char[] c = s.toCharArray();
        Stack<Integer> store = new Stack<Integer>();
        int[] right = new int[c.length];
        
        int res=0;
        for(int i=0;i<c.length;i++){
            if(c[i]=='('){
                store.push(i);
            }else{
                if(!store.isEmpty()){
                    right[i]=store.pop()+1;
                    int temp = right[i]-2;
                    if(temp>=0 && right[temp]>0){
                        right[i]=right[temp];    
                    } 
                    res=Math.max(i-right[i]+2,res);
                }
            }
        }
        return res;  
    }
}


#########

http://blog.csdn.net/abcbc/article/details/8826782