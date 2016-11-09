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