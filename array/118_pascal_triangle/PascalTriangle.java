/*
118. Pascal's Triangle
https://leetcode.com/problems/pascals-triangle/

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> generate(int numRows) {
        ArrayList<ArrayList<Integer>> result =
            new ArrayList<ArrayList<Integer>>();
            
        if (numRows < 1) {
            return result;
        }
        
        ArrayList<Integer> start = new ArrayList<Integer>();
        start.add(1);
        result.add(start);
        
        for (int i = 1; i < numRows; i++) {
            ArrayList<Integer> pre = result.get(i-1);
            ArrayList<Integer> vec = new ArrayList<Integer>();
            vec.add(1);
            
            for (int j = 1; j < i; j++) {
                int temp = pre.get(j-1) + pre.get(j);
                vec.add(temp);
            }
            
            vec.add(1);
            result.add(vec);
        }
        
        return result;
    }
}