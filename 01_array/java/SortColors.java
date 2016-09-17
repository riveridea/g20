/*

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort. First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

------------------------------------------------------
Method 1: to use the counting sort. but it will pass the array twice.

# http://blog.csdn.net/xudli/article/details/8633769

------------------------------------------------------

Method 2: take advatange of the only-three-possiblity value. Because we 
know the array will begin with 0 and end up with 2.

public class Solution {
    public void sortColors(int[] A) {
        int index = 0;
        int start = 0;
        int end = A.length -1;
        
        while (start <= end) {
            if (A[start] == 0) {
                A[index] = 0;
                index++;
                start++;
            } else if (A[start] == 2) {
                A[start] = A[end];
                A[end] = 2;
                end--;
            } else {
                start++;
            }
        }
        
        for (int i = index; i <= end; i++) {
            A[i] = 1;
        }
    }
}


# other solution
http://gongxuns.blogspot.com/2012/12/sort-colors-given-array-with-n-colored.html