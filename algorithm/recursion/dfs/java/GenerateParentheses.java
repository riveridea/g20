/*

Given n pairs of parentheses, write a function to
generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

统一dfs算法
# http://blog.csdn.net/u011095253/article/details/9158429

public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
        ArrayList<String> res = new ArrayList<String>();
        
        if (n <= 0) {
            return res;
        }
        
        dfs(res, "", n, n);
        
        return res;
    }
    
    public void dfs(ArrayList<String>res, String tmp, int left, int right) {
        if(left==0 && right==0) {
            res.add(tmp);
            return;
        }
        
        if (left>0) {
            dfs(res, tmp + '(', left-1, right);
        }
        
        if (left< right) {
            dfs(res, tmp + ')', left, right -1);
        }
    }
}


-----------------------------------------
采用递归树的思想，当左括号数大于右括号数时可以加左或者右括号，否则只能加左括号，
当左括号数达到n时，剩下全部加右括号。
*/


/*  Java */

public class Solution {
    public ArrayList<String> generateParenthesis(int n) {
         ArrayList<String> result = new ArrayList<String>();
         generate(result, "",0,0,n);
         return result;
    }



    private static void generate(ArrayList<String> result, 
                    String prefix, int leftCount, int rightCount,int totalPairs){
        if(leftCount == totalPairs){
            for(int i = 0; i < totalPairs - rightCount;i++){
                prefix += ")";
            }
            result.add(prefix);
            return;
         }
         
         generate(result, prefix + "(", leftCount + 1, rightCount, totalPairs);
         
         if(leftCount > rightCount) 
            generate(result, prefix +")", leftCount, rightCount + 1,totalPairs);
    }

}