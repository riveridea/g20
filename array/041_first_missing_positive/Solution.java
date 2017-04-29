/*
 41. First Missing Positive:
 https://leetcode.com/problems/first-missing-positive/
  
 Given an unsorted integer array, to find the first 
 missing positive integer.
 For exmaple, 
    Given [1, 2, 0], return 3;
    and [3, 4, -1, 1], return 2. // program outputs 1 ??          

 Your algorithm should run in O(n) time and use constant space.
*/


//思路：交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，
//寻找第一个不符合此要求的元素，返回其下标。整个过程需要遍历两次
//数组，复杂度为O(n)。


public class Solution {
    public int firstMissingPositive(int[] A) {
        
        int n = A.length;
        
        for (int i=0; i<n; ++i)
        {
            if (A[i] > 0 && A[i] < n)
            {
                if (A[i]-1 != i && A[A[i]-1] != A[i])
                {
                    int temp = A[A[i]-1];
                    A[A[i]-1] = A[i];
                    A[i] = temp;
                    --i;
                }
            }
        }

        for (int j=0; j<n; ++j)
            if (A[j]-1 != j)
               return j+1;

        return n+1;       
    }
}