/*
Q: Given an array of integers, find two numbers such 
   that they add up to a specific target number.

   The function twoSum should return indices of 
   the two numbers such that they add up to the target, 
   where index1 must be less than index2. Please note 
   that your returned answers (both index1 and index2) 
   are not zero-based.

   You may assume that each input would have exactly 
   one solution.

	Example: Input: numbers={2, 7, 11, 15}, target=9
		     Output: index1=1, index2=2
*

* 
* HashMap solution
* Time Complexity O(n)
* Space Complexity O(n)
*

 Step:
 1. scan from left to right, save the number and index to map.
 2. scan second time, and do the math.


* Or
* First Sort the array with O(nlgn)
* Then go through from both ends to middle. O(n).
* Important: if the order in the original array cannot
* be changed, the Hashtabel is the best solution.
*

*
* Additions From Google 
* 一个数组存放若干整数，一个数出现了奇数次，其余数出现了偶数次。找出出现奇数次的数是多少？
*/


#include <ioStream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            
            if (hashMap.find(left) != hashMap.end()) {
                if (i < hashMap[left]) {
                    result.push_back(i+1);
                    result.push_back(hashMap[left] +1);
                    break;
                }
                
                if (i > hashMap[left]) {
                    result.push_back(hashMap[left] +1 );
                    result.push_back(i+1);
                    break;
                }
            }
        }
        
        return result;
    }
};

int main() {

    Solution sol;
    
    vector<int> test1 = {4, 1, 2};
    vector<int>& test1Ref = test1;
    int target1 = 6;

    vector<int> res1 = sol.twoSum(test1Ref, target1);    
    cout << "The two indexes are: " << res1[0];
    cout << " and " << res1[1] << endl;
    

    vector<int> test2 = {2, 7, 11, 15};
    vector<int>& test2Ref = test2;
    int target2 = 9;

    vector<int> res2 = sol.twoSum(test2Ref, target2);    
    cout << "The two indexes are: " << res2[0];
    cout << " and " << res2[1] << endl;
}