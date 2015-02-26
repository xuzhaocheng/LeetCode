// 8 Palindrome Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include  <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)	return false;
		if (x < 10) return true;

		long long factor = 10;
		while(factor < x) {
			factor *= 10;
		}
		factor /= 10;

		while(x > 0) {
			if (x / factor != x % 10) return false;
			x  = (x - x / factor * factor) / 10;
			factor /= 100;
		}
		return true;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	if(solution.isPalindrome(1000000001))
		cout << "YES";
	else 
		cout << "No";
	cout << endl;
	return 0;
}

