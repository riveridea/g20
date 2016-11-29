/*
169. Majority Element
https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is 
the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always 
exist in the array.
*/

public class Solution {
	/*
    delete two numbers each time, the last one must be 
    the one with occur time more than [n/2] times.
	*/
    public int majorityElement(int[] nums) {
        
        int current = 0;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
        	if (count == 0) {
        		current = num[i];
        		count = 1;
        	} else {
        		if (num[i] == current) {
        			count ++;
        		} else {
        			count --;
        		}
        	}
        }

        return current;
    }

    // the other way is to sort the element.
    // the median number will be the target
}