/*
3 Sum:
https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S 
such that a + b + c = 0? Find all unique triplets in the array 
which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. 
(ie, a ≤ b ≤ c). The solution set must not contain duplicate triplets.
    
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

/*
Idea:
 3 Sum是two Sum的变种，可以利用two sum的二分查找法来解决问题。
 本题比two sum增加的问题有：解决duplicate问题，3个数相加返回数值而非index。
 首先，对数组进行排序。
 然后，从0位置开始到倒数第三个位置（num.length-3)，进行遍历，假定num[i]就
 是3sum中得第一个加数，然后从i+1的位置开始，进行2sum的运算。当找到一个3sum==0的
 情况时，判断是否在结果hashset中出现过，没有则添加。(利用hashset的value唯一性）
 因为结果不唯一，此时不能停止，继续搜索，low和high指针同时挪动。

 2. The more efficient way.  O(n^2)

After sorting the input array, 3 three pointers are initialized.
The first pointer goes from index 1 to index end-2.
The 2nd pointers goes from the current element(1st pointer) index + 1
The 3rd pointers goes from the last element in a reverse order.

Two iterations:
1. 1st pointer from 1 to index end-2
2. while (2nd<3rd)

Conditions:
1. if (array[1st]+array[2nd]+array[3rd]==0), get one result
2. if (array[1st]+array[2nd]+array[3rd]>0), 3rd -1
3. if (array[1st]+array[2nd]+array[3rd]<0), 2nd +1

*/
// more clear way
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        int length = nums.size();
        
        if (length < 3) {
            return results;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < length-2; i++) {
            if (i == 0 || nums[i] != nums[i-1]) { // remove duplicate at the beginning, but i-1 is a dangerous expression
                int low = i+1;
                int high = length-1;
                
                while (low < high) {
                    int sum = nums[i] + nums[low] + nums[high];
                    
                    if (sum == 0) {
                        vector<int> solution;
                        solution.push_back(nums[i]);
                        solution.push_back(nums[low]);
                        solution.push_back(nums[high]);
                        
                        results.push_back(solution);
                        
                        low++;
                        high--;
                        
                        // remove duplicate at second element
                        while (low < high && nums[low] == nums[low-1]) {
                            low++;
                        }
                        
                        // remove duplicate at third element
                        while (low < high && nums[high] == nums[high+1]) {
                            high--;
                        }
                        
                        
                    } else if (sum > 0) {
                        high --;
                    } else {
                        low ++;
                    }
                }
            }
        }
        
        return results;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            int target = 0-nums[i];
            
            int start = i+1;
            int end = len-1;
            
            while (start < end) {
                if ((nums[start] + nums[end]) == target) {
                    vector<int> solution;
                    solution.push_back(nums[i]);
                    solution.push_back(nums[start]);
                    solution.push_back(nums[end]);
                    
                    result.push_back(solution);
                    start++;
                    end--;
                    
                    // remove duplicates
                    while (start < end && nums[start] == nums[start-1]) {
                        start++;
                    }
                    
                    while (start < end && nums[end] == nums[end+1]) {
                        end--;
                    }
                } else if ((nums[start] + nums[end]) < target) {
                    start++;
                } else {
                    end--;
                }
            
                 if (i < len-1) {
                     while (nums[i] == nums[i+1]) {
                          i++;
                     }
                 }
            }
        }
        
        return result;
    }
};