// 7 String to Integer (atoi).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
		int len = strlen(str);
		int i = 0;
		int sign = 1;
		
		// find first non-whilespace characters
		while (str[i] == ' ' && i < len) i++;

		// find sign of number
		if (str[i] == '-') {
			sign = -1;
			i++;
		} else if (str[i] == '+') {
			i++;
		}

		long long ret = 0;
		long long factor = 1;
		while(str[i] <= '9' && str[i] >= '0' && i < len) {
			ret = 10 * ret + str[i] - '0';
			if (ret > INT_MAX) {
				if (sign > 0)	return INT_MAX;
				if (sign < 0)	return INT_MIN;
			}
			i++;
		}

		return sign * ret;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	cout << solution.atoi("2147483648") << endl;
	return 0;
}

