/*
Combination Sum II: 
https://leetcode.com/problems/combination-sum-ii

Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending 
order. (ie, a1 ≤ a2 ≤ … ≤ ak). The solution set must not contain 
duplicate combinations. For example, given candidate set 10,1,2,7,
6,1,5 and target 8, A solution set is: 

[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] <elem may be duplicated in the original set, though>
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        dfs(result, list, candidates, target, 0);
        return result;
    }
    
    void dfs(vector<vector<int>>& result, vector<int>& list, vector<int>& candidates, int target, int pos) {
        
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            result.push_back(list);
            return;
        }
        
        for (int i = pos; i < candidates.size(); i++) {
            list.push_back(candidates[i]);
            dfs(result, list, candidates, target-candidates[i],i+1);
            list.pop_back();
            
            while (i < candidates.size() -1 && candidates[i] == candidates[i+1]) {
                i++;
            }
        }
        
    }
};