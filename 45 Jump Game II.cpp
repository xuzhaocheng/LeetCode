#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <algorithm>

using namespace std;


/*
** 贪心算法
** 1) 找到当前index所能跳到的所有index中，下一步能跳到最远的index
** 即 index = {index | A[index] + index > A[j] + j, i < j, index <= A[i] + i}
** 2) 跳到这个index上
** 3) 重复步骤1，直到A[index]+index大于等于n-1
** 正确性：
** 设选取的index为i，那么可知A[i] + i > A[j] + j, 其中j为当前循环中的任意index
** 对于j < i,
** 若A[j] + j < i, 显然j不会出现在解中
** 若A[j] + j > i, 因为A[j] + j < A[i] + i, 那么[i, A[j] + j] ⊂ [i, A[i] + i]
** 对于[j, i), 的部分则被其他j < j' < i包含，而这部分显然不可能包含解。 
** 对于j > i,
** 因为A[j] + j < A[i] + i, 所以若最优解出现在A[j] + j中，那么也必然出现在A[i] + i中。
** 综上，贪心是正确的。
*/
class Solution {
public:
    int jump(int A[], int n) {
        if (n == 1) return 0;
    	int i = 0, ret = 0;
		
        while (i < n) {
            if (A[i] + i >= n - 1)  return ret + 1;

            int maxPos = 0, index;
            for (int j = i + 1; j <= A[i] + i; j++) {
                if (maxPos < A[j] + j) {
                    maxPos = A[j] + j;
                    index = j;
                }
            }
            ret++;
            i = index;
        }
    }
};

int main(void) {
	Solution s;
	int A[] = {5,9,3,2,1,0,2,3,3,1,0,0};
	cout << s.jump(A, sizeof(A) / sizeof(A[0])) << endl;
	return 0;
}