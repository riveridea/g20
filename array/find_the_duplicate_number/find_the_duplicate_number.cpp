/*
287. Find the Duplicate Number
https://leetcode.com/problems/find-the-duplicate-number

Given an array nums containing n + 1 integers where each 
integer is between 1 and n (inclusive), prove that at least 
one duplicate number must exist. Assume that there is only 
one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could 
be repeated more than once.
*/

// see: https://boweihe.me/?p=1920

public:
    int countLtEq(const vector<int>& nums, int n){
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= n)
                count ++;
        }
        return count;
    }
    
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int min = 1, max = n;
        int mid;
        int ltEqCnt;
        while(min < max){
            mid = (min + max)/2;
            ltEqCnt = countLtEq(nums, mid);
            if(ltEqCnt <= mid){
                //[min, mid]是正常的，找另一边
                min = mid+1;
            } else {
                max = mid;
            }
        }
        return min; // min == max
    }
};
