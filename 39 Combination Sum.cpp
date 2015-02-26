#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <algorithm>

using namespace std;

class Solution {
public:
	void dfs(vector<vector<int> > &res, vector<int> &candidates, int i, vector<int> &ele, int sum, int target) {
		if (sum == target) {
			std::sort(ele.begin(), ele.end());
			res.push_back(ele);
			return;
		}

		if (i == candidates.size()) return;
		if (sum + candidates[i] > target) return;
		

		int cnt = 0;
		while (cnt * candidates[i] + sum <= target) {
			if (cnt != 0)
			 	ele.push_back(candidates[i]);
			
			if (cnt * candidates[i] + sum <= target) {
				dfs(res, candidates, i+1, ele, cnt * candidates[i] + sum, target);
			}

			cnt++;
		}

		for (int j = 0; j < cnt - 1; j++)
			ele.pop_back();

	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        vector<int> ele;
        vector<int> newCandidates;

        std::sort(candidates.begin(), candidates.end());

        newCandidates.push_back(candidates[0]);
       	for (int i = 1; i < candidates.size(); i++) {
       		if (newCandidates[newCandidates.size() - 1] != candidates[i]) {
       			newCandidates.push_back(candidates[i]);
       		}
       	}

        dfs(ret, newCandidates, 0, ele, 0, target);
        return ret;
    }
};

int main(void) {
	Solution s;
	int A[] = {8,7,4,3};
	int target = 11;
	vector<int> candidates;
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) 
		candidates.push_back(A[i]);

	vector<vector<int> > res = s.combinationSum(candidates, target);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}