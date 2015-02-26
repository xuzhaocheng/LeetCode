#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	int left, right, mid = 0;
    	left = 0, right = n - 1;
    	while (left <= right) {
    		mid = (left + right) >> 1;
    		if (A[mid] == target) return mid;

    		if (A[mid] < target) left = mid + 1;
    		else if (A[mid] > target) right = mid - 1;
    	}

    	if (left == mid + 1)	return left;
    	return mid;
    }
};

int main(void) {
	Solution s;
	int A[] = {1};
	cout << s.searchInsert(A, 0, 0) << endl;
	return 0;
}