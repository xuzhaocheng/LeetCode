#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if (n == 0 || n == 1) return n;

    	int k = 0;
    	for (int i = 0; i < n; i++) {
    		if (A[k] != A[i]) {
    			A[k+1] = A[i];
    			k++;
    		}
    	}
    	return k + 1;
    }

};

int main(void) {
	Solution s;
	int A[] = {1, 2, 2, 2, 3, 4 ,5, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9};
	// int A[] = {1, 1, 2};
	int n = s.removeDuplicates(A, sizeof(A) / sizeof(A[0]));
	cout << n << endl;
	for (int i = 0; i < n; i++) 
		cout << A[i] << " ";
	cout << endl;

	return 0;
}