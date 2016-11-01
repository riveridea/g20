/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/


/*
对于一组有限个数的数据来说，它们的中位数是这样的一种数：这群数据里的一半的数据比它大，而另外一半数据比它小。 计算有限个数的数据的中位数的方法是：把所有的同类数据按照大小的顺序排列。如果数据的个数是奇数，则中间那个数据就是这群数据的中位数；如果数据的个数是偶数，则中间那2个数据的算术平均值就是这群数据的中位数。
*/


public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        int m = A.length;
        int n = B.length;
        
        if ((m+n) % 2 != 0) {
            return (double) findMedianSortedArraysHelper(A, B, (m+n)/2,
                0, m-1, 0, n-1);
        } else {
             return (findMedianSortedArraysHelper(A, B, (m+n)/2,
                0, m-1, 0, n-1) + 
                    findMedianSortedArraysHelper(A, B, (m+n)/2 -1,
                0, m-1, 0, n-1)) * 0.5;           
        }
    }
    
    public double findMedianSortedArraysHelper(int A[], int B[], int k,
            int aStart, int aEnd, int bStart, int bEnd) {
        
        int aLen = aEnd - aStart + 1;
        int bLen = bEnd - bStart + 1;
        
        if (aLen == 0)
		    return B[bStart + k];
	    if (bLen == 0)
	    	return A[aStart + k];
    	if (k == 0)
	    	return A[aStart] < B[bStart] ? A[aStart] : B[bStart];
 
      	int aMid = aLen * k / (aLen + bLen); // a's middle count
    	int bMid = k - aMid - 1; // b's middle count
     
    	// make aMid and bMid to be array index
    	aMid = aMid + aStart;
    	bMid = bMid + bStart;
     
    	if (A[aMid] > B[bMid]) {
    		k = k - (bMid - bStart + 1);
    		aEnd = aMid;
    		bStart = bMid + 1;
    	} else {
    		k = k - (aMid - aStart + 1);
    		bEnd = bMid;
    		aStart = aMid + 1;
    	}
     
    	return findMedianSortedArraysHelper(A, B, k, aStart, aEnd, bStart, bEnd);  
            
    }
}


# http://blog.csdn.net/yysdsyl/article/details/4266515