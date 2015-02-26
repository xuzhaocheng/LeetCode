// 13 Roman to Integer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		int num = 0;
		int units_sign  = 1, tens_sign = 1, hundreds_sign = 1, thousands_sign = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 'I') {
				num += 1 * units_sign;
			} else if (s[i] == 'V') {
				num += 5;
				units_sign = -1;
			} else if (s[i] == 'X') {
				units_sign = -1;
				num += 10 * tens_sign;
			} else if (s[i] == 'L') {
				num += 50;
				tens_sign = -1;
			} else if (s[i] == 'C') {
				num += 100 * hundreds_sign;
				tens_sign = -1;
			} else if (s[i] == 'D') {
				num += 500;
				hundreds_sign = -1;
			} else if (s[i] == 'M') {
				num += 1000 * thousands_sign;
				hundreds_sign = -1;
			}
		}
		return num;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	cout << s.romanToInt("MMMCMXCIX") << endl;
	return 0;
}

