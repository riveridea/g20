/*
Plus One:
https://leetcode.com/problems/plus-one/

Given a non-negative number represented as an array of 
digits, plus one to the number. The digits are stored 
such that the most significant digit is at the head of 
the list.

*/

/*
思路是维护一个进位，对每一位进行加一，然后判断进位，
如果有继续到下一位，否则就可以返回了，因为前面不需
要计算了。有一个小细节就是如果到了最高位进位仍然存
在，那么我们必须重新new一个数组，然后把第一个为赋
成1（因为只是加一操作，其余位一定是0，否则不会进最
高位）。因为只需要一次扫描，所以算法复杂度是O(n)，n是数组的长度。而空间上，一般情况是O(1)，但是如果数是全9，那么是最坏情况，需要
O(n)的额外空间。

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        
        if (length == 0) {
            return digits;
        }
        
        int carry = 1;
        
        for (int i = length-1; i >= 0; i--) {
            int digit = (digits[i]+ carry) % 10;
            carry = (digits[i]+ carry) / 10;
            
            digits[i] = digit;
            
            if (carry == 0) {
                return digits;
            }
        }
        
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

int main() {


	return 0;
}

/*
后续可以问一些比较基本的扩展问题，
比如可以扩展这个到两个数组相加，
或者问一些OO设计，假设现在要设计
一个BigInteger类，那么需要什么
构造函数，然后用什么数据结构好，
用数组和链表各有什么优劣势。
*/