/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

/* Java */
//http://mattcb.blogspot.com/2012/11/permutations-leetcode.html
/* Algorithms

If you pass the last position
--print the string
--return

Else
--For each letter in the input string
----If it is marked as used, skip to the next letter
----else place the letter in the current positioin
------Mark the letter as used
------permutate remaining letters starting at current postion+1
------Mark the letter as unused.

--end
*/
// Good to go
public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {

        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(num.length==0) return res;
        boolean[] visit = new boolean[num.length];
        int[] buff = new int[num.length];
        dfs(res,buff,visit,num,0);
        return res;
    }
    
    public void dfs(ArrayList<ArrayList<Integer>> res, int[]buff,boolean[] visit, int num[],int pos){
        if(pos==num.length){
            ArrayList<Integer> sub  = new ArrayList<Integer>();
            for(int n: buff) sub.add(n); //Arrays.asList(array)
            res.add(sub);
            return;
        }
        for(int i=0;i<num.length;i++){
            if(visit[i] == false){
                buff[pos]=num[i]; 
                // 原解法 此处 buff[i] = num[pos] 反了，在做 permutation II的时候会出问题。
                visit[i]=true;
                dfs(res,buff,visit,num,pos+1);
                visit[i]=false;
            }
        }
    }
}


public class Solution {
    public ArrayList<ArrayList<Integer>> permute(int[] num) {
        ArrayList<ArrayList<Integer>> list = 
            new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> a = new ArrayList<Integer>();
        a.add(num[0]);
        list.add(a);

        for(int i = 1; i < num.length; i++) {
            list = insert(list, num[i]);
         }
        return list;
}

public ArrayList<ArrayList<Integer>> insert(
                    ArrayList<ArrayList<Integer>> list, int num) {
    ArrayList<ArrayList<Integer>> resultList = 
            new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.get(i).size() + 1; j++) {
                ArrayList<Integer> temp = 
                    new ArrayList<Integer>(list.get(i));
                temp.add(j, num);
                resultList.add(temp);
            }
        }
        
        return resultList;
    }
}



/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/


/*
# http://blog.csdn.net/lbyxiafei/article/details/9338491

# got the idea from this link, sort the array first， then jump the duplicates elements

*/


public class Solution {
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        if(num.length==0) return res;
        boolean visit[] = new boolean[num.length];
        int [] buff = new int[num.length];
        Arrays.sort(num);
        dfs(res,buff,visit,num,0);
        return res;
    }
    public void dfs(ArrayList<ArrayList<Integer>> res, int[]buff,boolean[] visit, int num[],int pos){
        if(pos==num.length){
            ArrayList<Integer> sub  = new ArrayList<Integer>();
            for(int n: buff) sub.add(n); 
            res.add(sub);
            return;
        }
        for(int i=0;i<num.length;i++){
            if(visit[i] == false){
                buff[pos]=num[i]; // 此处易错
                visit[i]=true;
                dfs(res,buff,visit,num,pos+1);
                visit[i]=false;

                while (i+1<num.length && num[i] == num[i+1]) {
                    i++;
                }
            }
        }
    }
}
