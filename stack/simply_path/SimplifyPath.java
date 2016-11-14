/*
71. Simplify Path
https://leetcode.com/problems/simplify-path/

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"


Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

http://fisherlei.blogspot.com/2013/01/leetcode-simplify-path.html
http://discuss.leetcode.com/questions/247/simplify-path

try:
http://blog.csdn.net/xudli/article/details/8633304
*/


public class Solution {
    public String simplifyPath(String path) {
        if (path == null || path.length() == 0) return "/";
    
        Stack<String> stack = new Stack<String>();
        String[] splits = path.trim().split("/");
        for (String s : splits) {
            if (s == null || s.length() == 0 || s.equals(".")) {
                // Do nothing;
            } else if (s.equals("..")) {
                // Pop if stack is not empty;
                if (stack.size() > 0) stack.pop();
            } else {
                // Push all others to stack.
                stack.push(s);
            }
        }
    
        // Remember, stack can be empty.
        if (stack.isEmpty()) return "/";
    
        StringBuffer buf = new StringBuffer();
        while (!stack.isEmpty()) {
            buf.insert(0, stack.pop());
            buf.insert(0, "/");
        }
    
        return buf.toString();        
    }
}
