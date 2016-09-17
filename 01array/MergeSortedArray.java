/*

Given two sorted integer arrays A and B, merge B into A 
as one sorted array.

Note:
You may assume that A has enough space to hold additional
elements from B. The number of elements initialized in A
and B are m and n respectively

*/

/* Java */

public class Solution {
    public void merge(int A[], int m, int B[], int n) {
        while (n > 0) {
        	if (m > 0 && A[m-1] > B[n-1]) {
        		A[n+m-1] = A[m-1];
        		m--;
        	} else {
        		A[n+m-1] = B [n-1];
        		n--;
        	}
        }
    }
}


/*
you are given two sorted arrays, A and B, and A has a large enough buffer at the end 
to hold B. Write a method to merge B into A in sorted order.
*/

public class MerginTwoArrays {

	// a -- n,  b -- m

	public static void merge(int []a, int []b, int n, int m) {
		int k = m + n - 1; //index of last location of array b in array a.
		int i = n - 1;
		int j = m - 1;

		while (i >= 0 && j >= 0) {
			if (a[i] > b[j]) {
				a[k--] = a[i--];
			} else {
				a[k--] = b[j--];
			}
		} 

		while (j >= 0) {
			a[k--] = b[j--];
		}
	}

}