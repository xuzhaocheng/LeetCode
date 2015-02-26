// 6 Reverse Integer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
#include <iostream>

using namespace std;

/*
class Solution {
public:
    int reverse(int x) {
        int n = x < 0 ? -x : x;
		vector<int> vec;
		int index = 0;
		bool flag = false;
		while (n > 0) {
			int digit = n % 10;
			if (digit != 0) {
				vec.push_back(digit);
				flag = true;
				index++;
			} else if (flag) {
				vec.push_back(digit);
				index++;
			}
			n = n / 10;
		}

		long long ret = 0;
		long long factor = 1;
		for (int i = vec.size() - 1; i >= 0; i--) {
			ret += vec[i] * factor;
			factor *= 10;
		}

		if (ret > 0x7fffffff)
			return 0;
		
		if (x < 0)	ret = -ret;
		return ret;
    }
};

*/

class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
		x = abs(x);

		long long ret = 0;
		while (x > 0) {
			ret = ret * 10 + x % 10;
			x = x / 10;
			if (ret > INT_MAX)	return 0;
		}

		return ret * sign;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	cout << solution.reverse(1000000003) << endl;
	return 0;
}

