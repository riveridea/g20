/*


Given a sorted array of integers, find the starting and ending 
position of a given target value. Your algorithm's runtime complexity 
must be in the order of O(log n). If the target is not found in 
the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
*/

//两次 binary search， 一次找比target大一个的，一次找比target小一个的



/* Java */

public class Solution {
    public int[] searchRange(int[] A, int target) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int[] ret = new int[2];
        ret[0] = search_left_most(A, target);
        ret[1] = search_right_most(A, target);
        return ret;
    }   
    
    public int search_left_most(int[] A, int target) {
        int left = 0;
        int right = A.length - 1;
        while(right >= left) {
            int mid = (right + left) / 2;
            if(A[mid] == target) {
                if(mid == 0) return mid;
                if(A[mid-1] == target) right = mid - 1;
                else return mid;
            } else if(A[mid] > target) {
                right = mid - 1;
            } else if(A[mid] < target) {
                left = mid + 1;
            }   
        }   
        return -1; 
    }   
    
    public int search_right_most(int[] A, int target) {
        int left = 0;
        int right = A.length - 1;
        while(right >= left) {
            int mid = (right + left) / 2;
            if(A[mid] == target) {
                if(mid == A.length - 1) return mid;
                if(A[mid+1] == target) left = mid + 1;
                else return mid;
            } else if(A[mid] > target) {
                right = mid - 1;
            } else if(A[mid] < target) {
                left = mid + 1;
            }
        }
        return -1;
    }
}


####

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> range(2, -1);
        int lower = 0;
        int upper = n;
        int mid;

        // Search for lower bound
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (A[mid] < target)
                lower = mid + 1;
            else
                upper = mid;
        }

        // If the target is not found, return (-1, -1)
        if (A[lower] != target)
            return range;
        range[0] = lower;

        // Search for upper bound
        upper = n;
        while (lower < upper) {
            mid = (lower + upper) / 2;
            if (A[mid] > target)
                upper = mid;
            else
                lower = mid + 1;
        }
        range[1] = upper - 1;

        return range;
    }
};
       