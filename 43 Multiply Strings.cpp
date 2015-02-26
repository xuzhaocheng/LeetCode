#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

/*
class Solution {
public:
    string multiply(string num1, string num2) {
    	if (num1 == "1")	return num2;
    	if (num2 == "1")	return num1;
    	if (num1 == "0" || num2 == "0")	return "0";

    	string res(num1.length() + num2.length(), '0');

    	for (int i = num1.length() - 1; i >= 0; i--) {
    		string single_multi_res;
    		int tens = 0;
    		for (int j = num2.length() - 1; j >= 0; j--) {
    			int digit_res = (num1[i] - '0') * (num2[j] - '0') + tens;
    			int digit = digit_res % 10;
    			tens = digit_res / 10;
    			single_multi_res.push_back(digit + '0');
    		}

    		if (tens > 0)	single_multi_res.push_back(tens + '0');

    		int index = num1.length() - i - 1;
    		tens = 0;
    		for (int k = 0; k < single_multi_res.length(); k++) {
       			int digit_res = res[index] - '0' + single_multi_res[k] - '0' + tens;
    			res[index] = digit_res % 10 + '0';
    			tens = digit_res / 10;
    			index++;
    		}

			while (tens > 0) {
				int digit_res = res[index] - '0' + tens;
				res[index] = digit_res % 10 + '0';
				tens = digit_res / 10;
				index++;
			}	
    	}

    	for (int i = res.length() - 1; i > 0 && res[i] == '0'; i--)
    		res.pop_back();

    	std::reverse(res.begin(), res.end());
    	return res;
    }
};*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int i, j;
        int m = num1.size(), n = num2.size();
        // max (m + n) digits
        vector<int> product(m + n, 0);
        string result;

        // reverse for ease of calc
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // digit i * digit j contributes to digit i + j
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                product[i + j] += (num1[i] - '0') * (num2[j] - '0');
                // 留到下次计算时进位
                product[i + j + 1] += product[i + j] / 10;
                product[i + j] %= 10;
            }
        }

        // remove leading 0; keep last 0 if all 0
        i = m + n - 1;
        while (i > 0 && 0 == product[i])
            i--;

        while (i >= 0)
            result += to_string(product[i--]);

        return result;
    }
};


int main(void) {
	Solution s;
	long long  a = 16665l * 1334335l;
	cout << s.multiply("9", "9") << endl;
	cout << a << endl;
	return 0;
}