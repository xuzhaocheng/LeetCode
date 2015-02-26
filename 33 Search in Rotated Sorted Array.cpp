#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;


/*
** 分治法！
** 有序的部分就二分，无序的就一直二分直到有序！
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;

        while (left <= right) {
        	int mid = (left + right) / 2;
        	if (A[mid] == target) return mid;
        	
        	// 左半部分有序
        	if (A[mid] >= A[left]) {
        		if (target < A[mid] && target >= A[left]) {
        			// target一定在左半部分，或者不存在整个数组中
        			right = mid - 1;
        		} else {
        			// target在无序的右半部分
        			left = mid + 1;
        		}
        	} else {	// 右半部分有序
        		if (target > A[mid] && target <= A[right]) {
        			// target一定在右半部分，或者不存在整个数组中
        			left = mid + 1;
        		} else {
        			// target在无序的左半部分
        			right = mid - 1;
        		}
        	}
        }

        return -1;
    }
};

int main(void) {
	Solution s;
	int A[] = {1, 3, 5};
	cout << s.search(A, sizeof(A) / sizeof(A[0]), 1) << endl;
	return 0;
}