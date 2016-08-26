/*
https://leetcode.com/problems/permutations

Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

/* Java */
//http://mattcb.blogspot.com/2012/11/permutations-leetcode.html
/* Algorithms

If you pass the last position
--print the string
--return

Else
--For each letter in the input string
----If it is marked as used, skip to the next letter
----else place the letter in the current positioin
------Mark the letter as used
------permutate remaining letters starting at current postion+1
------Mark the letter as unused.

--end
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        if (nums.size() == 0) {
            return result;
        }
        
        vector<int> list;
        // 0 means not visited
        vector<int> visited(nums.size(), 0);
        dfs(nums, 0, visited, list, result);
        return result;
    }
    
    void dfs(vector<int>& nums, int pos, vector<int>& visited, vector<int>& list, vector<vector<int>>& result) {
        
        if (pos == nums.size()) {
            result.push_back(list);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] == 0) {
                visited[i] = 1;
                list.push_back(nums[i]);
                dfs(nums, pos+1, visited, list, result);
                list.pop_back();
                visited[i] = 0;
            }
        }
    }
};