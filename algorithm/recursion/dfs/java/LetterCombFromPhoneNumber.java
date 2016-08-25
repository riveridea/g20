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

public class LetterCombFromPhoneNumber {

	public ArrayList<String> letterCombinations(String digits) {
        char[][] table = {{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
                            {'j','k','l'},{'m','n','o'},{'p','q','r','s'},
                            {'t','u','v'},{'w','x','y','z'}};      
                            
        ArrayList<String> res = new ArrayList<String>();
        dfs(digits, table, "", res);
        return res;
    }
    
    public void dfs(String digits, char[][] table, 
                    String tmp, ArrayList<String> res) {
        if (digits.length() == 0) {
            res.add(tmp);
            return;
        }
        
        for (int i=0; i < table[digits.charAt(0) - '0' - 1].length; i++) {
            dfs(digits.substring(1), table, tmp+table[digits.charAt(0) - '0' -1][i], res);
    }

    public void main(String[] args) {

    }
}