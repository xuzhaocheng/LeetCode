// 17 Letter Combinations of a Phone Num.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		string letters[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		
		vector<string> ret(1, "");
		for (int i = 0; i < digits.size(); i++) {
			if (digits[i] == '1')	continue;

			vector<string> tmp = ret;
			ret.clear();
			for(int j = 0; j < letters[digits[i]-'0'].length(); j++) {
				for (int k = 0; k < tmp.size(); k++) {
					ret.push_back(tmp[k] + letters[digits[i] - '0'][j]);
				}
			}

		}
		return ret;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector <string> strs = s.letterCombinations("1234");
	for (int i = 0; i < strs.size(); i++) {
		cout << strs[i] << endl;
	}
	cout << strs.size() << endl;
	return 0;
}

