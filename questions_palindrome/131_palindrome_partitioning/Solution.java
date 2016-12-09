/*
PalindromePartitioning:
https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of 
the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

public class Solution {
    public ArrayList<ArrayList<String>> partition(String s) {  
        // Start typing your Java solution below  
        // DO NOT write main() function  
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();  
        ArrayList<String> tmp = new ArrayList<String>();  
        partitionImp(res, tmp, s);  
        return res;  
    }  
    
    private void partitionImp(ArrayList<ArrayList<String>> res, ArrayList<String> tmp, String s){  
        if(s.length() == 0){  
            res.add(new ArrayList<String>(tmp));  
            return;  
        }  
        for(int i=0; i<s.length(); i++){  
            String sub = s.substring(0, i+1);  
            if(isPartition(sub)){  
                tmp.add(sub);  
                partitionImp(res, tmp, s.substring(i+1));  
                tmp.remove(tmp.size()-1);  
            }  
        }  
    }  
    
    private boolean isPartition(String str){  
        int i=0, j=str.length()-1;  
        while(i < j)  
            if(str.charAt(i++) != str.charAt(j--))  
                return false;  
        return true;  
    }  
}