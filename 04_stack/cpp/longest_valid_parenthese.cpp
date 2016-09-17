/*
32. Longest Valid Parentheses
https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) 
parentheses substring.

For "(()", the longest valid parentheses substring is "()", 
which has length = 2.

Another example is ")()())", where the longest valid 
parentheses substring is "()()", which has length = 4.

reference http://zhihengli.blogspot.com/2013/08/
leetcode-longest-valid-parentheses.html

http://www.cnblogs.com/TenosDoIt/p/3771122.html
*/


#include <cstddef>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		const int length = s.size();
		stack<int> stack;   
		int maxLen = 0;
		int last = -1; 

		for (int i = 0; i < length; i++) {
			if (s[i] == '(') {
				stack.push(i);
			} else if (s[i] == ')') {
				if (stack.empty() == false) {
					stack.pop();

					if (stack.empty() == true) {
						maxLen = max(maxLen, i - last);
					} else {
						maxLen = max(maxLen, i - stack.top());
					}
				} else {
					last = i;
				}
			}
		}   
    }

    int longestValidParentheses(string s) {
        const int len = s.size();
        stack<int> sta;
        int res = 0;
        sta.push(-1);//为了处理边界条件，在栈底添加-1
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
                sta.push(i);
            else
            {
                int topIndex = sta.top();
                if(topIndex >= 0 && s[topIndex] == '(')//s[i]可以和s[a]匹配
                {
                    sta.pop();
                    if(res < i - sta.top())
						res = i - sta.top();
                }
                else sta.push(i);
            }
        }
        return res;
    }
};