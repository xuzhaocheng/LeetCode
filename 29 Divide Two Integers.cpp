// 29 Divide Two Intergers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// 两个数都要转成正数
// 两个负数
// 负数最小没法转成正数，需用long long
class Solution {
public:
    int divide(int dividend, int divisor) {
		if (divisor == 0)	return INT_MAX;
		if (divisor == 1)	return dividend;
		if (divisor == 2)	return dividend >> 1;
		if (dividend == 0)	return dividend;
		if (divisor == -2)	return -dividend >> 1;
		if (divisor == -1) {
			if (dividend == INT_MIN)	return INT_MAX;
			return -dividend;
		}

		int sign = 1;
		long long long_dividend = dividend;
		long long long_divisor = divisor;

		if ((dividend < 0 && divisor > 0)) {
			sign = -1;
			long_dividend = -long_dividend;
		} else if (dividend > 0 && divisor < 0) {
			sign = -1;
			long_divisor = -long_divisor;
		}

		if (long_divisor < 0) long_divisor = -long_divisor;
		if (long_dividend < 0) long_dividend = -long_dividend;

		if (long_dividend < long_divisor) return 0;

		long long sum = 0;
		int cnt = 0;
		while (sum <= long_dividend) {
			//cout << sum << endl;
			if (sum << 1 <= long_dividend && sum > 0) {
				sum = sum << 1;
				cnt = cnt << 1;
			} else if (sum > 0) {
				break;
			}else {
				sum += long_divisor;
				cnt++;
			}
		}

		long_dividend -= sum;
		int total = cnt;
		sum = sum >> 1;
		while (long_dividend >= long_divisor) {
			while (long_dividend < sum) {
				sum = sum >> 1;
				cnt = cnt >> 1;
			}

			long_dividend -= sum;
			sum = sum >> 1;
			cnt = cnt >> 1;
			total += cnt;
		}
		
		return sign == -1 ? - total : total;
    }
};

int main(int argc, _TCHAR* argv[])
{
	Solution s;
	int res;
	int dividend, divisor;

	dividend = 1;
	divisor = -1;
	res = s.divide(dividend, divisor);
	if (res != dividend / divisor) cout << dividend << " / " << divisor << endl;
	
	dividend = 2147483647;
	divisor = 3;
	res = s.divide(dividend, divisor);
	if (res != dividend / divisor) cout << dividend << " / " << divisor << endl;

	dividend = 10;
	divisor = 3;
	res = s.divide(dividend, divisor);
	if (res != dividend / divisor) cout << dividend << " / " << divisor << endl;

	dividend = 1038925803;
	divisor = -2147483648;
	res = s.divide(dividend, divisor);
	if (res != dividend / divisor) cout << dividend << " / " << divisor << endl;

	dividend = -2147483648;
	divisor = -1;
	res = s.divide(dividend, divisor);
	if (res != INT_MAX) cout << dividend << " / " << divisor << endl;

	return 0;
}

