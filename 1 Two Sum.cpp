// 1 Two Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::sort;


struct node {
	int v;
	int index;
};


bool sort1(const struct node &v1, const struct node &v2) {
	return v1.v < v2.v;
}


// 先排序，然后check两两之和
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> ret;

		vector<int>::iterator it;
		vector<struct node> nodes;
		for (it = numbers.begin(); it != numbers.end(); it++) {
			struct node n;
			n.v = *it;
			n.index = it - numbers.begin() + 1;
			nodes.push_back(n);
		}

		std::sort(nodes.begin(), nodes.end(), sort1);

		vector<struct node>::iterator n_it;
		vector<struct node>::iterator n_itt;
		for (n_it = nodes.begin(); n_it != nodes.end() - 1; n_it++) {
			for (n_itt = n_it + 1; n_itt != nodes.end(); n_itt++) {
				if ((*n_itt).v + (*n_it).v == target) {
					if ((*n_it).index < (*n_itt).index) {
						ret.push_back((*n_it).index);
						ret.push_back((*n_itt).index);
					} else {
						ret.push_back((*n_itt).index);
						ret.push_back((*n_it).index);
					}
					
					return ret;
				}
			}
		}
		return ret;
	}

};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(7);
	numbers.push_back(11);
	numbers.push_back(5);

	vector<int> ret = solution.twoSum(numbers, 7);

	cout << ret[0] << " " << ret[1] << endl;

	return 0;
}

