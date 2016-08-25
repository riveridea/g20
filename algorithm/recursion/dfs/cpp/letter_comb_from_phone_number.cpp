/*

https://leetcode.com/problems/letter-combinations-of-a-phone-number

Given a digit string, return all possible letter combinations that 
the number could represent. A mapping of digit to letters (just 
like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, 
your answer could be in any order you want.

Considering input will be a list of Integer. From Google Interview
*/


class Solution {

public:  
    vector<string> letterCombinations(string digits) {  
        vector<string> res;  
        length=digits.size();  

        if(length==0) {
        	return res;
        }

        char* tmp=(char*)malloc(sizeof(char) * (length+1)); 

        dfs(res, 0, digits, tmp); 

        return res;  
    }  

private:  
    char map[10][5]={" ", "", "abc", "def", "ghi", "jkl", 
    			     "mno", "pqrs", "tuv", "wxyz"};  
    int top=0;
    int length=0;  

    void dfs(vector<string>& res, int index, string digits, char* tmp){  

        if(index >= length){  
            tmp[index]=0;  
            string letters = string(tmp);  
            res.push_back(letters);  
            return;  
        }  

        int digit=digits[index]-'0';  

        for(int i = 0; map[digit][i]; i++){  
            tmp[index] = map[digit][i];  
            dfs(res,index+1,digits,tmp);  
        }  
    }  
};