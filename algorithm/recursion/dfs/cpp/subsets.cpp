/*
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/* standerlize the DFS method
http://blog.csdn.net/u011095253/article/details/9158397
*/


public class Solution {
    public ArrayList<ArrayList<Integer>> subsets(int[] S) {
        ArrayList<ArrayList<Integer>> subsets = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> subset = new ArrayList<Integer>();
        
        subsets.add(subset);
        Arrays.sort(S);
        
        dfs(subsets, subset, S, 0);
        
        return subsets;
    }
    
    public void dfs(ArrayList<ArrayList<Integer>> subsets, ArrayList<Integer> subset,
                    int[] S, int pos) {
        for (int i = pos; i < S.length; i++) {
            subset.add(S[i]);
            subsets.add(new ArrayList<Integer>(subset));
            dfs(subsets, subset, S, i+1);
            subset.remove(subset.size() -1);
        }                    
    }
}