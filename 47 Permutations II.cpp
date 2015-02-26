#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <algorithm>

using namespace std;

/*
** DFS
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<vector<int> > ret;
    	vector<int> permution;
    	std::sort(num.begin(), num.end());
    	permute(num, permution, ret);
    	return ret;
    }

    void permute(vector<int> num, vector<int> &permution, vector<vector<int> > &ret) {
    	if (num.size() == 0) {
    		ret.push_back(permution);
    		return;
    	}

    	for (int i = 0; i < num.size(); i++) {
    		// 每次选取剩余数字中的一个数，加入排列中
    		// 并将这个数字从待选数组中删除。递归。
    		vector<int> n = num;
    		n.erase(n.begin() + i);
    		permution.push_back(num[i]);
    		permute(n, permution, ret);
    		permution.pop_back();
    		
    		// 避免出现重复的组合
    		int j;
    		for (j = i + 1; j < num.size() && num[j] == num[i]; j++);
    		i = j - 1;
    	}
    }
};

int main(void) {
	Solution s;
	int A[] = {3, 3, 1, 1};
	vector<int> num;
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
		num.push_back(A[i]);

	vector<vector<int> > res = s.permuteUnique(num);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}