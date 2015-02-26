#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include "string.h"

using namespace std;


/* 用横向，纵向，九宫格3个限制条件来筛选当前可填的数字
** 每行、列、九宫格，用一个int的低9位来记录。0表示未出现的数字，1表示已经出现的数字
** 所以可以将当前位置的行、列、九宫格的掩码相“或”来筛选出0的位。
** 回溯找出可行解
*/
class Solution {
public:
	void setBitmap(int constraints[][9], int i, int j, int num) {
		int mask = 1 << (num - 1);
		constraints[0][i] |= mask;
		constraints[1][j] |= mask;
		constraints[2][(i/3)*3+j/3] |= mask;
	}

	void resetBitmap(int constraints[][9], int i, int j, int num) {
		int mask = (1 << (num - 1)) ^ 0xFFFF;
		constraints[0][i] &= mask;
		constraints[1][j] &= mask;
		constraints[2][(i/3)*3+j/3] &= mask;
	}

	bool solve(vector<vector<char> > &board, int constraints[][9], int count) {
		
		if (count >= 81)	return true;

		int i = count / 9;
		int j = count % 9;
		bool res = false; 
		
		if (board[i][j] != '.') {
			res = solve(board, constraints, count + 1);
			if (res) return true;
		} else {
			int acceptableMask = constraints[0][i] | constraints[1][j] | constraints[2][(i/3)*3+j/3];
			for (int k = 0; k < 9; k++) {
				if (((acceptableMask >> k) & 1) == 0) {
					board[i][j] = '1' + k;
					setBitmap(constraints, i, j, k + 1);
					res = solve(board, constraints, count + 1);
					
					if (res) return true;
					else {
						resetBitmap(constraints, i, j, k + 1);
						board[i][j] = '.';
					}
				}
			}

		}

		return false;
	}

    void solveSudoku(vector<vector<char> > &board) {
        int constraints[3][9];
        memset(constraints, 0, sizeof(int) * 3 * 9);
		for (int i = 0; i < board.size(); i++) {
	   		for (int j = 0; j < board[i].size(); j++) {
        		if (board[i][j] != '.') {
        			int num = board[i][j] - '0';
        			int mask = 1 << (num - 1);
        			constraints[0][i] |= mask;
        			constraints[1][j] |= mask;
        			constraints[2][(i/3)*3+j/3] |= mask;
        		}
    		}
    	}

    	solve(board, constraints, 0);
    }
};

int main(void) {
	Solution s;
	string lines[9] = 
	// {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};
	{"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
	vector<vector<char> >board;
	for (int i = 0; i < 9; i++) {
		vector<char> line;
		for (int j = 0; j < 9; j++) {
			line.push_back(lines[i][j]);
		}
		board.push_back(line);
	}

	s.solveSudoku(board);

	for (int i = 0; i < board.size(); i++) {
		if (i % 3 == 0) {
			for (int k = 0; k < 12; k++)
				cout << "- ";
			cout << endl;
		}
		for (int j = 0; j < board[i].size(); j++) {
			if (j % 3 == 0)	cout << '|' << " ";
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}