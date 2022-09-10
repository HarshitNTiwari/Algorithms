/*
Author: Harshit Tiwari
Date: 24-08-2022
https://leetcode.com/problems/valid-sudoku/
*/

class Solution {
public:
	bool checkSudoku(vector<vector<char>>& board, int n, int m) {
		vector<int> check(10, 0);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[n + i][m + j] != '.') {
					int num = board[n + i][m + j] - '0';
					if (check[num] == 1)
						return false;
					check[num] = 1;
				}
			}
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			vector<int> check(10, 0);
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					if (check[num] == 1)
						return false;
					check[num] = 1;
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			vector<int> check(10, 0);
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					int num = board[j][i] - '0';
					if (check[num] == 1)
						return false;
					check[num] = 1;
				}
			}
		}
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				if (!checkSudoku(board, i, j))
					return false;
			}
		}
		return true;
	}
};