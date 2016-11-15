
/*
136. Single Number
https://leetcode.com/problems/single-number/

Given an array of integers, every element appears twice 
except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?
*/


class Solution {
public:

/*
Single Number:
https://leetcode.com/problems/single-number/

Given an array of integers, every element appears twice
except for one. Find that single one.

Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory? OR
The requirement is O(n) time and O(1) space.
*/

// XOR is a good way, we can use the property 
// that A XOR A = 0, and A XOR B XOR A = B.
// x^x = 0, x^0 = x。并且异或有交换律：1^1^0 = 0 = 1^0^1

    int singleNumber1(vector<int>& nums) {
        int target = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            target ^= nums[i];
        }
        
        return target;
    }
};



/* 
Single Number II:
https://leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three 
times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

http://www.acmerblog.com/leetcode-single-number-ii-5394.html
http://bangbingsyb.blogspot.com/2014/11/leetcode-single-number-i-ii.html
*/


class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for(int i=31; i>=0; i--) {
            int sum = 0;
            int mask = 1<<i;
            for(int j=0; j<n; j++) {
                if(A[j] & mask) 
                    sum++;
            }
            res = (res<<1) + (sum%3);
        }
        return res;
    }
};

