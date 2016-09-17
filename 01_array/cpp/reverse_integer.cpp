/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321


Have you thought about this?

If the integer's last digit is 0, 
what should the output be? ie, 
cases such as 10, 100.

Did you notice that the reversed integer 
might overflow? Assume the input is a 
32-bit integer, then the reverse of 
1000000003 overflows. How should you 
handle such cases?

For the purpose of this problem, 
assume that your function returns 0 
when the reversed integer overflows.


ref: http://www.cnphp6.com/archives/64172

g++ reverse_integer.cpp
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;        
    }
};

int main() {

	int input1 = -123;
	int input2 = 100;

	Solution sol;

	cout << "input1 = -123" << sol.reverse(input1)  << endl;
	cout << "input2 = 100"  << sol.reverse(input2)  << endl;

	return 0;
}