// 14 Longest Common Prefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0)	return "";
		if (strs.size() == 1)	return strs[0];

		for (int i = 0; i < strs[0].length(); i++) {
			for (int j = 1; j < strs.size(); j++) {
				if (i >= strs[j].length() || strs[j][i] != strs[0][i])
					return strs[0].substr(0, i);
			}
		}

		return strs[0];
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> strs;
	/*strs.push_back("aaaacsdfasdf");
	strs.push_back("aaaacsffasdfssfasf");
	strs.push_back("1aaaca");
	*/
	Solution s;
	cout << s.longestCommonPrefix(strs) << endl;
	return 0;
}

