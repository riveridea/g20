/*
https://leetcode.com/problems/combinations/

Given two integers n and k, return all possible combinations 
of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

public class Combinations {

}

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        
    }
}

/* Got idea from this post
# http://blog.unieagle.net/2012/09/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Acombination%EF%BC%8Cckn%EF%BC%8C%E4%BB%8En%E4%B8%AD%E9%80%89%E5%87%BAk%E4%B8%AA/
*/

so my answer will be

/*
Java
*/

public class Solution {
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
        
        if (k <=0 || n <1) {
            return ret;
        }
        
        ArrayList<Integer> set = new ArrayList<Integer>();
        dfs(n, k, 1, set, ret);
        return ret;
    }
    
    public void dfs(int n, int k, int pos, ArrayList<Integer> set,
                    ArrayList<ArrayList<Integer>> ret) {
        if (set.size() == k) {
            ret.add(new ArrayList<Integer>(set)); // otherwise set will be modified
            return;
        }
        
        for (int i = pos; i <= n; i++) {
            set.add(i);
            dfs(n, k, i+1, set, ret);
            set.remove(set.size()-1);
        }
    }
}


###############
public class Solution {
    public ArrayList<ArrayList<Integer>> combine(int n, int k) {
        if (n < k) {
            return null;
        }
        
        ArrayList<ArrayList<Integer>> result 
            = new ArrayList<ArrayList<Integer>>();
            
        if (k == 1) {
            for (int i = 1; i <= n; i++) {
                ArrayList<Integer> al = new ArrayList<Integer>();
                al.add(i);
                result.add(al);
            }
            
            return result;
        }
        
        for (int i=n; i >= k; i--) {
            for (ArrayList<Integer> al : combine(i-1, k-1)) {
                al.add(i);
                result.add(al);
            }
        }
        
        return result;
    }
}
