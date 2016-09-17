/*
3Sum Closest:
https://leetcode.com/problems/3sum-closest/

Given an array S of n integers, find three integers in S such 
that the sum is closest to a given number, target. Return the
sum of the three integers. You may assume that each input would
have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
idea:
3sum问题的变种。一样的遍历每个数，对剩余数组进行双指针扫描。区别仅仅在于当：
sum = A[left] + A[right]
(1) sum = target时直接返回
(2) sum != target时，在相应移动left/right指针之前，先计算abs(sum-target)
的值，并更新结果。
*/

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3) return INT_MAX;
        sort(num.begin(),num.end());
        int minDiff = INT_MAX;
        for(int i=0; i<num.size()-2; i++) {
            int left=i+1, right = num.size()-1;
            while(left<right) {
                int diff = num[i]+num[left]+num[right]-target;
                if(abs(diff)<abs(minDiff)) minDiff = diff;
                if(diff==0) 
                    break;
                else if(diff<0)
                    left++;
                else
                    right--;
            }
        } 
        return target+minDiff;
    }
};