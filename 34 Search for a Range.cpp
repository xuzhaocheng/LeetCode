#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
	int findLowestIndex(int A[], int left, int right, int target) {
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == target) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}

		return left;
	}

	int findHighestIndex(int A[], int left, int right, int target) {
		while (left <= right) {
			int mid = (left + right) / 2;
			if (A[mid] == target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}

		return right;
	}


    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret(2, -1);
        int left, right;
        left = 0;
        right = n - 1;
        int low, high;
        low = high = -1;
        while (left <= right) {   	
        	int mid = (left + right) / 2;
        	if (A[mid] == target) {
        		low = findLowestIndex(A, left, mid - 1, target);
        		high = findHighestIndex(A, mid + 1, right, target);
        		break;
        	}
        	if (A[mid] < target) {
        		left = mid + 1;
        	} else if (A[mid] > target) {
        		right = mid - 1;
        	}
        }
        ret[0] = low;
        ret[1] = high;
        return ret;
    }
};

int main(void) {
	Solution s;
	int A[] = {5, 7, 7, 8, 8, 10};
	int target = 8;
	vector<int> res = s.searchRange(A, sizeof(A) / sizeof(A[0]), target);
	cout << "[" << res[0] << ", " << res[1] << "]" << endl;
	return 0;
}