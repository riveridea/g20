/*
18. 4 Sum
https://leetcode.com/problems/4sum/

Given an array S of n integers, are there elements a, b, c, and d in S such that 
a + b + c + d = target? Find all unique quadruplets in the array which gives the 
sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/


/* Good Solution */

public class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        ArrayList<ArrayList<Integer>> rl = new ArrayList<ArrayList<Integer>>();
        
        if(num == null || num.length < 4) 
            return rl;
        HashSet<ArrayList<Integer>> rll = new HashSet<ArrayList<Integer>>();
        
        Arrays.sort(num);
        
        for(int i = 0; i < num.length - 3; i++) {
            for(int j = i + 1; j < num.length - 2; j++) {
                int m = j+1;
                int n = num.length-1;
            
                while(m < n) {
                    if (num[m] + num[n] < target - num[i] - num[j]) {
                        m++;
                    } else if (num[m] + num[n] > target - num[i] - num[j]){
                        n--;
                    } else {
                        ArrayList<Integer> tmp = new ArrayList<Integer>();
                        tmp.addAll(Arrays.asList(num[i], num[j], num[m], num[n]));
                        rll.add(tmp);
                    
                        do {
                            m++;
                        } while (m<n && num[m]==num[m-1]);
            
                        do {
                            n--;
                        } while(m<n && num[n]==num[n+1]);
                    }
                }
            }
        }
        
    rl.addAll(rll);
    return rl; 
    }
}


/* Java */

public class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        ArrayList<ArrayList<Integer>> rl = new ArrayList<ArrayList<Integer>>();
        if(num == null || num.length < 4) 
            return rl;
        HashSet<ArrayList<Integer>> rll = new HashSet<ArrayList<Integer>>();
        Arrays.sort(num);
        for(int i = 0; i < num.length - 3; i++)
            for(int j = i + 1; j < num.length - 2; j++)
                for(int m = j + 1, n = num.length - 1; m < n;)
                    if(num[m] + num[n] == target - num[i] - num[j]){
                        ArrayList<Integer> tmp = new ArrayList<Integer>();
                        tmp.addAll(Arrays.asList(num[i], num[j], num[m++], num[n--]));
                        rll.add(tmp);
                    }
                    else if(num[m] + num[n] < target - num[i] - num[j]) m++;
                    else n--;
        rl.addAll(rll);
        return rl;        
    }
}