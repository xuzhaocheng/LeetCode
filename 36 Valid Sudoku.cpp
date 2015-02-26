#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include "string.h"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int lines[9], rows[9], grids[9];

        memset(lines, 0, sizeof(int) * 9);
        memset(rows, 0, sizeof(int) * 9);
        memset(grids, 0, sizeof(int) * 9);

        for (int i = 0; i < board.size(); i++) {
        	for (int j = 0; j < board[i].size(); j++) {
        		if (board[i][j] != '.') {
        			int num = board[i][j] - '0';
        			int mask = 1 << (num - 1);

        			int res = lines[i] | mask;
        			if (lines[i] == res) {
        				return false;
        			}
        			else lines[i] = res;

        			res = rows[j] | mask;
        			if (rows[j] == res)	{
        				return false;
        			}
        			else rows[j] = res;

        			res = grids[(i/3)*3+j/3] | mask;
        			if (grids[(i/3)*3+j/3] == res) {
        				return false;
        			}
        			else grids[(i/3)*3+j/3] = res;
        		}
        	}
        }

        return true;
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

	bool res = s.isValidSudoku(board);
	if (res) 
		cout << "true" << endl;
	else 
		cout << "false" << endl;
	return 0;
}