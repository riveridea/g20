/*
60. Permutation Sequence
https://leetcode.com/problems/permutation-sequence/

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

public class Solution {
    public String getPermutation(int n, int k) {
        
    }
}

/*
http://gongxuns.blogspot.com/2012/12/leetcode-permutation-sequence.html
http://discuss.leetcode.com/questions/237/permutation-sequence
http://blog.csdn.net/havenoidea/article/details/12837441
http://blog.unieagle.net/2012/10/16/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Apermutation-sequence/


public class Solution {
    public String getPermutation(int n, int k) {
        // Start typing your Java solution below
        // DO NOT write main() function
        boolean[] output = new boolean[n];
        StringBuilder buf = new StringBuilder("");
        int[] res = new int[n];
        res[0]=1;
        for(int i=1;i<n;i++)
            res[i]=res[i-1]*i;
        
        for(int i=n-1;i>=0;i--){
            int s=1;
            while(k>res[i]){
                s++;
                k-=res[i];
            }
            for(int j=0;j<n;j++){
                if(j+1<=s && output[j]){
                    s++;
                }
            }
            output[s-1]=true;
            buf.append(Integer.toString(s));
        }        
        return buf.toString();
    }
}


*/