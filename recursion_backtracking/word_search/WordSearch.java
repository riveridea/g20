/*
Word Search:
https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically 
neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

以board上的每个cell为出发点，利用depth first search向上下左右四个方向
搜索匹配word。搜索的时候要考虑board的边界，cell是否已经在DFS的路径上被
用过，以及cell上的值是否与word的当前字符匹配。为了跟踪DFS的路径避免同一个
cell被访问多次，使用一个visited矩阵来代表board上任意的cell(i, j)是否
已经被访问过。

*/

public class Solution {
    public boolean exist(char[][] board, String word) {
        
    }
}