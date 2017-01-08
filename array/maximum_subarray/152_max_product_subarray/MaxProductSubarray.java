/*
https://leetcode.com/problems/maximum-product-subarray/
152. Maximum Product Subarray

Find the contiguous subarray within an array 
(containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/


// product can be negative or postive, need to be considered.
public class MaxProductSubarray {
    public int maxProduct(int[] nums) {
        if (nums == null || nums.length == 0) {
        	return 0;
        }

        int maxProduct = nums[0];
        int maxTmp = nums[0];
        int minTmp = nums[0];

        // time complexity is O(n)
        for (int i = 1; i < nums.length; i++) {
        	int max = maxTmp * nums[i];
        	int min = minTmp * nums[i]; 
        	// if nums[i] is negative, so the product 
        	// might turn to be positive

        	maxTmp = Math.max(Math.max(max, min), nums[i]);
        	minTmp = Math.min(Math.min(max, min), nums[i]);

        	maxProduct = Math.max(maxTmp, maxProduct);
        }

        return maxProduct;
    }
}