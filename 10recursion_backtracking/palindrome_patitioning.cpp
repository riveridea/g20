/*
https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

/*
Idea:
从左往右遍历string并取其substring，如果当前的substring是一个回文
，保存，递归；如果不是，继续循环，取下一个字符加入到substring，
直到substring的长度等于原来string的长度。

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(res, tmp, s);
        return res;
    }
    
    void dfs(vector<vector<string>> &res, vector<string> tmp, string s) {
        if (s.length() == 0) {
            res.push_back(tmp);
        }
        
        for (int i = 1; i <= s.length(); i++) {
            string subString = s.substr(0, i);
            
            if (isPalindrome(subString)) {
                tmp.push_back(subString);
                dfs(res, tmp, s.substr(i));
                tmp.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        string originalString = s;
        reverse(s.begin(), s.end());
        if (s.compare(originalString) == 0) {
            return true;
        } else {
            return false;
        }
    }

    void DisplayVector(const vector<string>& vecInput) {
    for (auto iElement = vecInput.begin();
            iElement != vecInput.end();
            ++iElement) {
        cout << *iElement << '+';
    }

    cout << endl;
    }
};


int main() {
    Solution s;
    s.partition(string("a"));

    cout << "a is palindrome?" << s.isPalindrome(string("a")) << endl;

    return 0;
}