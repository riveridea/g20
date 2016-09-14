/*
https://leetcode.com/problems/generate-parentheses

Given n pairs of parentheses, write a function to
generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> genearteParenthesis(int n) {
        vector<string> res;
        string comb;

        dfs(n, 0, 0, comb, res);
        return res;
    }

    void dfs(int n, int left, int right, string &comb, vector<string> &res) {
        if (left == n && right == n) {
            res.push_back(comb);
            return; 
        }

        if (left < n) {
            comb.push_back('(');
            dfs(n, left+1, right, comb, res);
            comb.pop_back('(');
        }

        if (right < left) {
            comb.push_back(')');
            dfs(n, left, right+1, comb, res);
            comb.pop_back();
        }
    }

};




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

    // insert "(" and ")" into a temp string until numbers of them 
    // equal to n. Then we get one solution
    // as long as "(" quantity less than N, we can insert "("
    // if "(" is more than ")", we can insert ")"

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

int main() {

    int n = 3;

    // print the content of a vector


    return 0;
}