/*
N-Queens:
https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' 
placement, where 'Q' and '.' both indicate a queen and an empty space 
respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

Same Question:
<<Cracking The Coding Interview 5th>> Question 9.9

# Write an algorithm to print all ways of arranging eight queens on an 8*8 chess
# board so that none of them share the same row, column or diagonal. In this case,
# "diagonal" means all diagonals, not just the two that bisect the board.

http://blog.csdn.net/u011095253/article/details/9158473
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
    }
};


import java.util.ArrayList;

public class Solution3 {
    public ArrayList<String[]> solveNQueens(int n) {
        ArrayList<String[]> res = new ArrayList<String[]>();
        int[] loc = new int[n];
        dfs(res,loc,0,n);
        System.out.println(res.size());
        return res;
    }
    
    public void dfs(ArrayList<String[]> res, int[] loc, int cur, int n){
        if(cur==n) 
            printboard(res,loc,n);
        else{
            for(int i=0;i<n;i++){
                loc[cur] = i; // 第 cur 行， 第 i 列 放个 Queen，看看行不行
                if(isValid(loc,cur))
                    dfs(res,loc,cur+1,n);
            }
        }
    }
    
    public boolean isValid(int[] loc, int cur){
        for(int i=0;i<cur;i++){ //判断放第 cur行的这个Queen 会不会和前cur-1
                                //行的Queen冲突。
            if(loc[i]==loc[cur]||Math.abs(loc[i]-loc[cur])==(cur-i))
                return false;
        }
        return true;
    }
    
    public void printboard(ArrayList<String[]> res, int[] loc, int n){
        String[] ans = new String[n];
        for(int i=0;i<n;i++){
            StringBuilder row = new StringBuilder();
            for(int j=0;j<n;j++){
                if(j==loc[i]) row.append("Q");
                else row.append("#");
            }
            ans[i] = row.toString();
            System.out.println(ans[i]);
        }
        System.out.println();
        res.add(ans);
    }
    
    public static void main(String[] args) {
        new Solution3().solveNQueens(8);
    }    
}