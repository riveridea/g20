/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/


public class Solution {
    public int search(int[] A, int target) {
    
        if (A == null) {
            return -1;
        }
       int start = 0, 
            end = A.length-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(A[mid]==target)
                return mid;
            if(A[mid]>target && (A[end]>A[mid] || A[end]<target) 
                || A[mid]<target && A[end]>A[mid] && A[end]<target){
                    end=mid-1;
            }else{
                start=mid+1;
            }
         
        }
        return -1;       
    }
}
