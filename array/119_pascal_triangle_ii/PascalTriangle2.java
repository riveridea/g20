/*
119. Pascal's Triangel II
https://leetcode.com/problems/pascals-triangle-ii/

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        ArrayList<Integer> resultList = new ArrayList<Integer>();
        if (rowIndex == 0) {
            resultList.add(1);
            return resultList;
        }
        // Initial
        resultList.add(1);
        resultList.add(1);
    
        for (int i = 2; i <= rowIndex; i++) {
            resultList.add(1, resultList.get(0) + resultList.get(1));       
            for (int j = 2; j < resultList.size() - 1; j++) {
                resultList.set(j, resultList.get(j) + resultList.get(j + 1));
            }
        }
    
        return resultList;  
    }
}