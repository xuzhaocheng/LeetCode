#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	int j = 0;
    	for (int i = 0; i < n; i++) {
    		if (elem != A[i]) {
    			if (j != i)
    				A[j] = A[i];
    			j++;
    		}
    	}
        return j;
    }
};

int main(void) {
	Solution s;
	int A[] = {2, 2, 2, 2};
	int n = s.removeElement(A, sizeof(A) / sizeof(A[0]), 2);
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}