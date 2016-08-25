/*
https://leetcode.com/problems/combinations/

Given two integers n and k, return all possible combinations 
of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <vector>
#include <iostream>

using namespace std; 

class Solution {
public:
    vector<vector<int>> Combine(int n, int k) {
        
        vector<vector<int>> res;

        if (k <=0 || n < 1 || k >n) {
        	return res;
        }

        vector<int> set;
        DFS(n, k, 1, set, res);

        return res;
    }

    void DFS(int n, int k, int pos, vector<int>& set, vector<vector<int>>& res) {
    	if (set.size() == k) {
    		res.push_back(set);
    		return;
    	}

    	for (int i = pos; i <= n; i++) {
    		set.push_back(i);
    		DFS(n, k, i+1, set, res);
    		set.pop_back();
    	}
    }

    void PrintNestedVector(vector<vector<int>>) {
    
    }
};

int main() {
    Solution s;
    int n = 4;
    int k = 2;

    vector<vector<int>> result;
    result = s.Combine(n, k);
    PrintNestedVector(result);

    return 0;
}
