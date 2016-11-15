/*
67. Add Binary
https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum 
(also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() || b.empty()) {
            return "";
        }
        
        int a_len = a.length();
        int b_len = b.length();
        
        int carry = 0;
        string result("");
        
        // adding from the end
        while (a_len>0 || b_len >0) {
            int sa = 0;
            int sb = 0;
            
            if (a_len>0) {
                sa = a[a_len-1] - '0';
            }
            
            if (b_len >0) {
                sb = b[b_len-1] - '0';
            }
            
            int temp = carry + sa + sb;
            result = to_string(temp%2) + result;
            carry = temp/2;
            
            a_len--;
            b_len--;
        }
        
        //cout << "result value is: " << result << endl;
        //cout << "carry value is: " << carry << endl;

        return (carry==0) ? result : "1" + result;
    }
};


int main() {
	string a("1");
	string b("1");

	Solution s;
	cout << "1 + 1 = " << s.addBinary(a, b) << endl;

	return 0;
}