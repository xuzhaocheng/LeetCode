// 15 3Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
		std::sort(num.begin(), num.end());
		vector<vector<int>> ret;
		for (int i = 0; i < num.size(); i++) {
			// Avoid duplicate triples
			if (i > 0 && num[i] == num[i-1])	continue;
			for (int j = i + 1; j < num.size(); j++) {
				// Avoid duplicate triples
				if (j > i + 1 && num[j] == num[j-1]) continue;
				int total = num[i] + num[j];
				for (int z = j + 1; z < num.size(); z++) {
					if (num[z] + total > 0) break;
					if (num[z] + total == 0) {
						vector<int> vec;
						vec.push_back(num[i]);
						vec.push_back(num[j]);
						vec.push_back(num[z]);
						ret.push_back(vec);
						break;
					}
				}
			}
		}

		return ret;
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;

	int n[] = {0, 0, 0, 0, 0, 0};

	vector<int> v;

	for ( int i = 0; i < sizeof(n) / sizeof(n[0]); i++) {
		v.push_back(n[i]);
	}

	vector<vector<int>> vec = s.threeSum(v);

	for (int i = 0 ; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

