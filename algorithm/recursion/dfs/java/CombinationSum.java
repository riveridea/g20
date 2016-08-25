
public class CombinationSum {

}

/*
Combination Sum: 
https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in 
non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, A solution 
set is: 

[7] 
[2, 2, 3] 

*/

class SolutionI {  
    public ArrayList<ArrayList<Integer>> combinationSum(int[] a, int target) {  
 
        ArrayList<ArrayList<Integer>> res=new ArrayList<ArrayList<Integer>>();  
        ArrayList<Integer> list=new ArrayList<Integer>();  
        Arrays.sort(a);  
        
        dfs(res, list, a, target, 0);
         
        return res;  
    }  
    
    public void dfs(ArrayList<ArrayList<Integer>> res, ArrayList<Integer> list,
                    int[] a, int target, int pos) {
    
        if (target < 0) {
            return;
        }
        
        if (target == 0) {
            res.add(new ArrayList(list));
            return;
        }
        
        for (int i = pos; i < a.length; i++) {
            list.add(a[i]);
            dfs(res, list, a, target-a[i], i);
            list.remove(list.size()-1);
        }
    }       
}  


/*
Combination Sum II:
https://leetcode.com/problems/combination-sum-ii

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

class SolutionII {
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] num, int target) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();  
        ArrayList<Integer> tmp = new ArrayList<Integer>();  
        Arrays.sort(num);  
        dfs(res,tmp,num,target,0);  
        return res;             
    }
    
    
     public void dfs(ArrayList<ArrayList<Integer>> res, 
                ArrayList<Integer> tmp, int[] num, 
                int target, int pos){  
        if(target<0) return;  
        if(target==0){  
            res.add(new ArrayList<Integer>(tmp));  
            return;  
        }  
        
        for(int i=pos; i<num.length;i++){  
            tmp.add(num[i]);  
            dfs(res,tmp,num,target-num[i],i+1);  
            tmp.remove(tmp.size()-1);  

            while(i<num.length-1&&num[i]==num[i+1]) 
            	i++;  
        }  
    }  
}