// 12 Integer to Roman.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		string s[10] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
		string hundreds[9] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		string tens[9] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		string roman_str;
		
		if (num / 1000 > 0) {
			for (int i = 0; i < num / 1000; i++)
				roman_str.push_back('M');
			num -= num / 1000 * 1000;
		}

		if (num / 100 > 0) {
			roman_str.append(hundreds[num / 100 - 1]);
			num -= num / 100 * 100;
		}


		if (num / 10 > 0) {
			roman_str.append(tens[num / 10 - 1]);
			num -= num / 10 * 10;
		}

		if (num > 0)
			roman_str.append(s[num-1]);

		return roman_str;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	int n[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 23, 26, 37, 48, 59, 64, 75, 80, 99, 501, 550, 530, 707, 890, 1500, 1800, 900, 3999};

	for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++)
		cout << n[i] << ": " << s.intToRoman(n[i]) << endl;
	//cout << s.intToRoman(2) << endl;
	return 0;
}

