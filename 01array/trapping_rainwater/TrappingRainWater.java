/*
42 Trapping Rain Water
http://oj.leetcode.com/problems/trapping-rain-water/

Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it is able to 
trap after raining.

For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

Refer to http://oj.leetcode.com/problems/trapping-rain-water/ for the figure. 
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being 
*/


/*  Use this solution
http://blog.csdn.net/kenden23/article/details/17115097

* 这里是两边往中间遍历，记录当前较低的那个边为 secHight，
* 然后利用这个第二高点减去这两个最长边之间，而且是当前历经的柱子，剩下就装水容量了。
* 时间复杂度 O(n)


public class Solution {
    public int trap(int[] A) {
        int area = 0;  
    
        if(A.length<3) 
            return area;
            
        int secHight = 0;  
        int left = 0;  
        int right = A.length-1;  

        while (left < right){  
            if (A[left] < A[right]){  
                secHight = Math.max(A[left], secHight);  
                area += secHight-A[left];  
                left++;  
            } else {  
                secHight = Math.max(A[right], secHight);  
                area += secHight-A[right];  
                right--;  
            }  
        }  
        return area;        
    }
}

*/


-------------------------------------------------------------------

# good explanation
http://blog.unieagle.net/2012/10/31/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Atrapping-rain-water/

public class Solution {
    public int trap(int[] A) {
        int res = 0;
        if(A.length<3) 
            return res;

        int[] left = new int[A.length-2],
              right = new int[A.length-2];

        for(int i=0;i<A.length-2;i++)
            left[i]=i>0?Math.max(left[i-1],A[i]):A[i];

        for(int i=A.length-3;i>=0;i--)
            right[i]=i<A.length-3?Math.max(right[i+1],A[i+2]):A[i+2];

        for(int i=0;i<A.length-2;i++){
            int temp = Math.min(left[i],right[i]);

            if(temp>A[i+1])
                res+=temp-A[i+1];
        }
        
        return res;        
    }
}