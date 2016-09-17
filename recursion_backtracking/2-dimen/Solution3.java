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

    // javac Solution3.java
    // java Solution
}