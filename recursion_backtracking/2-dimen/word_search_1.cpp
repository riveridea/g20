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

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.empty() || board[0].empty()) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(findWord(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
    
    bool findWord(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, string &word, int index) {
        if(index==word.size()) return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || visited[row][col] || board[row][col]!=word[index]) 
            return false;
            
        visited[row][col] = true;
        if(findWord(board, visited, row-1, col, word, index+1)) return true;  
        if(findWord(board, visited, row+1, col, word, index+1)) return true;
        if(findWord(board, visited, row, col-1, word, index+1)) return true;
        if(findWord(board, visited, row, col+1, word, index+1)) return true;
        visited[row][col] = false;
        return false;
    }
};


// timeout solution, duplicated path searched, guess
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.length() == 0) {
            return true;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        char c = word[0];
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] = word[0]) {
                    board[i][j] = ' ';
                    if (dfs(board, word.substr(i), i, j)) {
                        return true;
                    }
                    
                    board[i][j] = c;
                }
            }
        }
    }
    
    
    bool dfs(vector<vector<char> >& board, string word, int x, int y) {
        if (word.length() == 0) {
            return true;
        }
        
        int index[4][4]  = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        char c = word[0];
        
        for (int d = 0;  d < 4; d ++) {
            
            int i = x + index[d][0];
            int j = y + index[d][1];
            
            if (i >= 0 && i < board.size() && j >= 0 
                    && j < board[0].size() 
                    && board[i][j] == c) {
                board[i][j] = ' ';
                if (dfs(board, word.substr(1), i, j)) {
                    return true;
                }
                
                board[i][j] = c;
            }
        }
        
        return false;
    }
};