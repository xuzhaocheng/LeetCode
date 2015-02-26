#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
class Solution {
public:
	void dfs(unordered_map<string, bool> &resultMap, vector<vector<int> > &res, vector<int> &num, int i, vector<int> &ele, int sum, int target) {
		if (sum == target) {
			string key;
			for (int j = 0; j < ele.size(); j++) 
				key.push_back(ele[j] + '0');

			if (resultMap.find(key) == resultMap.end()) {
				res.push_back(ele);
				resultMap[key] = true;
			}
			return;
		}

		if (i == num.size()) return;
		if (sum + num[i] > target) return;
		

		dfs(resultMap, res, num, i+1, ele, sum, target);

		if (num[i] + sum <= target) {
			ele.push_back(num[i]);
			dfs(resultMap, res, num, i+1, ele, num[i] + sum, target);
			ele.pop_back();
		}

	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> ele;
        unordered_map<string, bool> resultMap;

        std::sort(num.begin(), num.end());

        dfs(resultMap, ret, num, 0, ele, 0, target);
        return ret;
    }
};*/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());

        vector<vector<int>> res;
        vector<int> cur;
        int cur_sum = 0;
        backtrack(num, target, 0, res, cur, cur_sum);

        return res;
    }

    void backtrack(const vector<int> &num, int target, int low,
        vector<vector<int>> &res, vector<int> &cur, int &cur_sum) {

        if (cur_sum == target) {
            res.push_back(cur);
            return;
        }

        if (cur_sum > target)
            return;

        for (int i = low; i < num.size(); ++i) {

            cur.push_back(num[i]);
            backtrack(num, target, i + 1, res, cur, cur_sum + num[i]);
            cur.pop_back();

            //handling duplicates:
            //simply don't start any new combinations with a duplicate
            while (i < num.size() - 1 && num[i + 1] == num[i])
                ++i;
        }
    }
};


int main(void) {
	Solution s;
	int A[] = {10,1,2,7,6,1,5};
	int target = 8;
	vector<int> num;
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) 
		num.push_back(A[i]);

	vector<vector<int> > res = s.combinationSum2(num, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}