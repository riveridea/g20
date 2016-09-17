/*
Evaluate Reverse Polish Notation:
https://leetcode.com/problems/evaluate-reverse-polish-notation

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        
        for (int i = 0 ; i < tokens.size(); i++) {
            if (isTokenOperator(tokens[i])) {
                int y = stack.top();
                stack.pop();
                int x = stack.top();
                stack.pop();
                stack.push(eval(x, y, tokens[i]));
                
            } else {
                stack.push(stoi(tokens[i], nullptr, 10));
            }
        }
        
        return stack.top();
    }
    
    bool isTokenOperator(string s) {
        
        if (s == "+" || s == "-" ||
                s == "*" || s == "/") {
            return true;
        } else {
            return false;
        }
    }
    
    int eval(int x, int y, string op) {
        if (op == "+") {
           return x+y;
        } else if (op == "-") {
            return x-y;
        } else if (op == "*") {
            return x*y;
        } else if (op == "/") {
            return x/y;
        }
    }
};