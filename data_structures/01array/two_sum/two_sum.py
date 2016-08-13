"""
https://leetcode.com/problems/two-sum/
第一遍遍历整个数组，用map记录数值和它的坐标.
第二遍遍历数组，判断（目标数字-当前数字）是否在map中.
如果在，且它的下标与当前数字的下标不相同，
则说明存在这两个数，返回坐标。
"""

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #hash用于建立数值到下标的映射
        hash = {}
        #循环nums数值，并添加映射
        for i in range(len(nums)):
            if target - nums[i] in hash:
                return [hash[target - nums[i]], i]
            hash[nums[i]] = i
        #无解的情况
        return [-1, -1]

if __name__ == "__main__":
    None