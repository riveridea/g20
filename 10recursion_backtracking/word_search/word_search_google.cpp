// Google Interview Question
/*

类似矩阵螺旋打印的题目

Here is a matrix, 
A B C D
T S A T
R O P H
M N O E

Example:
P
|
PA   PT   PH PE PO PN PO PS
|    |   
PAC  PAD  PAT PAh PAPx PAO PAS PAB
     |
     PTD

Print out all valid words based on the rule.     


class Solution {
public:

	vector<string> printWords(char[][] board) {
		int length = board.length;
		vector<string> result;
		char[][] flags = ;

		if (board == null || length == 0) {
			return result;
		}

		for (int i = 0; i < length -1; i++) {
			for (int j = 0; j < length - 1; j++) {
				if (checkDictionary(board[i][j] == true)) {
					result.push_back(string(board[i][j]));
				}

				helper(i, j, flags, "" + board[i][j], board, result);
			}
		}
	}

	void helper(int row, int column, char[][] flag, string tmp,
				char[][] board, vector<string> result) {
		if (checkDictionary(tmp + board[row][column]) == true) {
			result.push_back(tmp + board[row][column]);
		}

		if (flag[row][column+1] == false) {
			flag[row][column+1] = true;
			helper(row, column+1, flag, tmp, board, result);
		}

		if (flag[row-1][column+1] == false) {
			flag[row-1][column+1] = true;
			helper(row-1, column+1, flag, tmp, board, result);
		}

		if (flag[row-1][column] == false) {
			flag[row-1][column] = true;
			helper(row-1, column, flag, tmp, board, result);
		}

		if (flag[row-1][column-1] == false) {
			flag[row-1][column-1] = true;
			helper(row-1, column-1, flag, tmp, board, result);
		}

		if (flag[row][column-1] == false) {
			flag[row][column-1] = true;
			helper(row, column-1, flag, tmp, board, result);
		}

		if (flag[row+1][column-1] == false) {
			flag[row+1][column-1] = true;
			helper(row+1, column-1, flag, tmp, board, result);
		}		

		if (flag[row+1][column] == false) {
			flag[row+1][column] = true;
			helper(row+1, column, flag, tmp, board, result);
		}

		if (flag[row+1][column+1] == false) {
			flag[row+1][column+1] = true;
			helper(row+1, column+1, flag, tmp, board, result);
		}
	}
};
*/