#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

/*
** 二分递归
** 注意指数为负数的情况
** 注意负数转正数溢出的情况
*/
class Solution {
public:
    double pow(double x, int n) {
    	if (x == 1 || n == 1 || x == 0) return x;
    	if (x == -1) return (n % 2 == 0 ? 1 : -1);
    	if (n == 0)	return 1;
    	if (n < 0)	return pow(1/x, -n);

    	double num = pow(x, n/2);
    	if (n % 2 == 0)
    		return num * num;
    	else 
    		return num * num * x;
    }
};

int main(void) {
	Solution s;
	cout << s.pow(-1.00000, -2147483648) << endl;
	return 0;
}