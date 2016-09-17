/*
Given an array S of n integers, find three integers in S such 
that the sum is closest to a given number, target. Return the
sum of the three integers. You may assume that each input would
have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/* Java */
# Simply solution

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        if (num.length<3) { // if less than three items then return 0
            return Integer.MAX_VALUE;
        }
        
        Arrays.sort (num);
        int res = num[0] + num[1] + num[2] - target;
        for (int i = 0; i < num.length - 2; i++) {
            int j = i + 1, k = num.length - 1;
            
            while (j < k) {
                int d = num[i] + num[j] + num[k] - target;
                if (d == 0) 
                    return target;
            
                if (Math.abs (d) < Math.abs(res)) 
                    res = d;
            
                if (d < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return res + target;
    }
}


#####

/* Java */

public class Solution {
    public int threeSumClosest(int[] num, int target) {
        if (num.length<3) { // if less than three items then return 0
            return Integer.MAX_VALUE;
        }
        
        Arrays.sort(num);
        int res = num[0]+num[1]+num[2];
        for (int i=0; i<num.length-2; ++i) {
            if (i>0 && num[i]==num[i-1])  
                continue;

            for (int j=i+1; j<num.length-1; ++j) {
                if (j>i+1 && num[j]==num[j-1])  
                    continue;

                // binary search for the third
                int start=j+1, end=num.length-1;

                while (start<=end) {
                    int mid = (start+end)/2;
                    int curRes = num[i] + num[j] + num[mid];
                    int diff = curRes - target;

                    if ( Math.abs(diff) < Math.abs(res - target) ) {
                        res = curRes;
                    }

                    if (diff < 0) {
                        start = mid+1;
                    } else {
                        end = mid-1;
                    }
                }
            }
        }
        
        return res;
    }
}