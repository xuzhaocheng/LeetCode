// aaaaaa.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
		if (nRows ==1) return s;
        int row = 0;
		string *str = new string[nRows];
		bool up = true;
		for (int i = 0; i < s.length(); i++){
			str[row].push_back(s[i]);
			cout << s[i] << " add to row: " << row << endl;
			if (up) {
				if (row == nRows - 1) {
					row--;
					up = false;
				} else row++;
			} else {
				if (row == 0) {
					row++;
					up = true;
				} else row--;
			}
		}

		string ret;
		for (int i = 0; i < nRows; i++) {
			ret.append(str[i]);
		}
		delete []str;
		return ret;
    }
};






int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	string input = "PAYPALISHIRING";
	cout << solution.convert(input, 1) << endl;
	return 0;
}

