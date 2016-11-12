#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    /*
Remove Duplicates from Sorted Array II:
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first 
five elements of nums being 1, 1, 2, 2 and 3. It doesn't
matter what you leave beyond the new length.
*/

// 之前 leetcode上 跑通过了的，为什么改了一下就不过了
//http://blog.csdn.net/fightforyourdream/article/details/12883543
    int removeDuplicates(vector<int>& nums) {
        // index用来遍历数组，end保存新数组的最后位置
        int length = nums.size();
        int end = 0;
        int count = 0;
        
        if (length < 3) {
            return length;
        }
        
        for (int index = 1; index < length; index++) {
            // 重复的情况
            if (nums[end] == nums[index]) {
                // 当且仅当重复一次（共出现两次）的情况下才复制
                if (count == 0) {
                    nums[++end] = nums[index];
                } else {
                    count++;
                }
            } else {
                // 不重复的情况，更新end的位置，然后直接复制过去 
                nums[++end] = nums[index];
                // 重置counter
                count = 0;
            }
        }
        
        return end+1;
    }


};

int main() {
	vector<int> nums = {1, 1};
	Solution s;
	cout << "{1, 1} result is: " <<  s.removeDuplicates1(nums) << endl;
	return 0;
}