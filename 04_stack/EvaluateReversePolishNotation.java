/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

/* Java */

public class Solution {
    public int evalRPN(String[] tokens) {
 		int returnValue = 0;
		String operators = "+-*/";
 
		Stack<String> stack = new Stack<String>();
 
		for (String t : tokens) {
			if (!operators.contains(t)) {
				stack.push(t);
			} else {
				int b = Integer.valueOf(stack.pop());
				int a = Integer.valueOf(stack.pop());
				switch ((String)t) {
				case "+":
					stack.push(String.valueOf(a + b));
					break;
				case "-":
					stack.push(String.valueOf(a - b));
					break;
				case "*":
					stack.push(String.valueOf(a * b));
					break;
				case "/":
					stack.push(String.valueOf(a / b));
					break;
				}
			}
		}
 
		returnValue = Integer.valueOf(stack.pop());
 
		return returnValue;       
    }
}