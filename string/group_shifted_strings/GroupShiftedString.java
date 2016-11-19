/*
249. Group Shifted Strings

Given a string, we can "shift" each of its letter to its successive letter, 
for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
"abc" -> "bcd" -> ... -> "xyz"

Given a list of strings which contains only lowercase alphabets, group all 
strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

Note: For the return value, each inner list's elements must follow the 
lexicographic order.

Understand the problem:
The problem looks quite like the grouping anagrams. So the idea is the same: for 
each string, find out its "original" format, and check if the hash map contains 
this original string. If yes, put into the map. 

*/

public class Solution {
    public List<List<String>> groupStrings(String[] strings) {

    }
}