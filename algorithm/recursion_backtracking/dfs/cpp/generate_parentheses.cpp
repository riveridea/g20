/*

Given n pairs of parentheses, write a function to
generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        if (n <= 0) {
        	return res;
        }

        dfs(res, "", n, n);

        return res;
    }

    void dfs(vector<string> res, string tmp, int left, int right) {
    	if (left == 0 && right == 0) {
    		res.add(tmp);
    		return;
    	}

    	if (left > 0) {
    		dfs(res, tmp + '(', left - 1, right);
    	}

    	if (left < right) {
    		dfs(res, tmp + ')', left, right - 1);
    	}
    }
};