/*
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

/*
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