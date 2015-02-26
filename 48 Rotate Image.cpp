#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

/*
** (i,j)旋转后为(j, size-1-i)
** (j, size-1-i)旋转后为(size-1-i, size-1-j)
** (size-1-i, size-1-j)旋转后为(size-1-j, i)
** 三次交换把4个数都放到正确的位置上
** 已经旋转过的元素不再旋转
** 每处理矩阵的一行元素，矩阵未处理的元素就少一圈
** 所以第i行从第i个元素开始处理，直到第size-i-2
** 因为每处理一行，未处理的元素就少两行，所以只需处理size/2-1行
*/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	int size = matrix.size();

    	for (int i = 0; i < size / 2; i++) {
    		for (int j = i; j < size - i - 1; j++) {
    			swap(matrix[i][j], matrix[j][size-1-i]);
    			swap(matrix[i][j], matrix[size-1-j][i]);
    			swap(matrix[size-1-j][i], matrix[size-1-i][size-1-j]);
    		}
    	}
    }
};

/*
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        vector<vector<bool> > flag(matrix.size(), vector<bool>(matrix.size(), false));
        int size = matrix.size();

        for (int i = 0; i < matrix.size(); i++) {
        	for (int j = 0; j < matrix[i].size(); j++) {
        		if (flag[i][j]) continue;


        		int from_i = size - j - 1, from_j = i;
        		int _v = matrix[i][j];
        		matrix[i][j] = matrix[from_i][from_j];
        		flag[i][j] = true;

        		while (true) {
        			int dest_i = from_i, dest_j = from_j;

        			from_i = size - dest_j - 1;
        			from_j = dest_i;

        			if (!flag[dest_i][dest_j]) {
        				if (from_i == i && from_j == j) {
        					matrix[dest_i][dest_j] = _v;
        					flag[dest_i][dest_j] = true;
        					break;
        				}
        				matrix[dest_i][dest_j] = matrix[from_i][from_j];
        				flag[dest_i][dest_j] = true;
        			} else if (from_i == i && from_j == j) {
        				break;
        			}
        		}
        	}
        }
    }
};*/

int main(void) {
	Solution s;
	vector<vector<int> > matrix;
	
	vector<int> v;
	int n = 4;
	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}

	for (int i = 0; i < n; i++) {
		matrix.push_back(v);
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	s.rotate(matrix);

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	return 0;
}