/*
https://leetcode.com/problems/restore-ip-addresses

Given a string containing only digits, restore it by returning 
all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. 
(Order does not matter)
*/

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        
        if (s.length() < 4 || s.length() >12) {
            return res;
        }
        
        dfs(s, "", res, 0);
        
        return res;
    }
    
    void dfs(string s, string tmp, vector<string>& res, int count) {
        if (count == 3 && isValid(s)) {
            res.push_back(tmp + s);
            return;
        }
        
        for (int i = 1; i < 4 && i < s.length(); i++) {
            string subStr = s.substr(0, i);
            
            if (isValid(subStr)) {
                dfs(s.substr(i), tmp + subStr + string("."), res, count+1);
            }
        }
    }
    
    bool isValid(string s) {
        if (s.at(0) == '0') {
            if(s.compare("0"))
                return false;
            else 
                return true;
        }
        
        int num = stoi(s);
        
        return num<=255 && num>0;
    }
};