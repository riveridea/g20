/*
52. N-Queens II
https://leetcode.com/problems/n-queens-ii/

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total 
number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        
    }
};




public class Solution {
    int res; 
    public int totalNQueens(int n) {
        res = 0;
        if(n<=0) return res;
        int[] loc = new int[n];
        dfs(loc,0,n);
        return res;
    }
    
    public void dfs(int[] loc, int cur, int n){
        if (cur==n) {
            res+=1;
            return;
        }
        for(int i=0;i<n;i++){
            loc[cur] = i;
            if(isValid(loc,cur))
                dfs(loc,cur+1,n);
        }
    }
    
    public boolean isValid(int[] loc, int cur){
        for(int i=0;i<cur;i++){
            if(loc[i]==loc[cur]||Math.abs(loc[i]-loc[cur])==(cur-i))
                return false;
        }
        return true;
    }
}


http://blog.csdn.net/u011095253/article/details/9158473