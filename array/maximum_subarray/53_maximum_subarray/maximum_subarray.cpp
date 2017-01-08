/*
53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array 
(containing at least one number) which has 
the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the 
largest sum = 6.


More practice:
If you have figured out the O(n) solution, 
try coding another solution using the divide 
and conquer approach, which is more subtle.

g++ -std=c++11 maximum_subarray.cpp 
*/

#include <iostream>
#include <vector>
#include <climits>
//#include <limits.h> (C)

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

    	// std::numeric_limits<int>::max()
        int sum = INT_MIN;

        int tmp = 0;

        for (int i = 0; i < nums.size(); i++) {
        	if (tmp <= 0) {
        		tmp = nums[i];
        	} else {
        		tmp = tmp + nums[i];
        	}

        	if (sum < tmp) {
        		sum = tmp;
        	}
        }

        return sum;
    }
};

int main() {

	vector<int> array1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	Solution sol;    
	vector<int>& r_Array1 = array1;

	cout << "The array is: "  << endl;
	cout << "The maximum sum is: " << sol.maxSubArray(r_Array1) << "." << endl;


	return 0;
}