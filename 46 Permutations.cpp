#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

/*
** DFS
*/
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	vector<vector<int> > ret;
    	vector<int> permution;
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
    	}
    }
};

int main(void) {
	Solution s;
	int A[] = {1, 2, 3};
	vector<int> num;
	// for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	// 	num.push_back(A[i]);

	vector<vector<int> > res = s.permute(num);

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}