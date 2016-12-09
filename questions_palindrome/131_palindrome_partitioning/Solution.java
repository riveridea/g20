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

import java.util.ArrayList;

public class Solution {
    public ArrayList<ArrayList<String>> partition(String s) {  
        // Start typing your Java solution below  
        // DO NOT write main() function  
        ArrayList<ArrayList<String>> res = new ArrayList<ArrayList<String>>();  
        ArrayList<String> tmp = new ArrayList<String>();  
        partitionImp(res, tmp, s);  

        return res;  
    }  
    
    private void partitionImp(ArrayList<ArrayList<String>> res, 
                              ArrayList<String> tmp, String s){  
        if (s.length() == 0) {  
            res.add(new ArrayList<String>(tmp));  
            return;  
        }  

        for(int i=0; i<s.length(); i++){  
            String sub = s.substring(0, i+1);  

            if(isPalindrome(sub)){  
                tmp.add(sub);  
                partitionImp(res, tmp, s.substring(i+1));  
                tmp.remove(tmp.size()-1);  
            }  
        }  
    }  
     
    private boolean isPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s.charAt(i++) != s.charAt(j--)) {
                return false;
            }
        }

        return true;
    }

    public void printListOfList(ArrayList<ArrayList<String>> results) {
        System.out.println("[");

        for (ArrayList<String> result : results) {
            System.out.print("[");
            
            int count = 0;

            for (String string : result) {
                System.out.print(string);

                if (count < result.size() - 1) {
                    System.out.print(",");
                }

                count++;
            }

            System.out.print("]");
            System.out.print(",");
            System.out.println();
        }

        System.out.println("]");
    }


    public static void main (String args[]) {

        Solution s = new Solution();
        String input = "aab";
        ArrayList<ArrayList<String>> results = s.partition(input);
        s.printListOfList(results);
    }
}