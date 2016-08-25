/*
Combination Sum: 
https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in 
non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, A solution 
set is: 

[7] 
[2, 2, 3] 

*/


class Solution {
public:
        // vector<int> v = {2, 0, 1, 5, 9, 2, 7};
        //sort(v.begin(), v.end()); 
        //sort(v.begin(), v.end(), less<int>()); // greater<int>(), descending
    // passed in leetcode
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        dfs(result, list, candidates, target, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& list,
            vector<int>& candidates, int target, int pos) {
        
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            result.push_back(list);
            return;
        }
        
        for (int i = pos; i < candidates.size(); i++) {
            list.push_back(candidates[i]);
            dfs(result, list, candidates, target-candidates[i], i);
            list.pop_back();
        }
    }
};