#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
          	while (A[i] > 0 && A[i] != i + 1 && A[i] <= n && A[i] != A[A[i] - 1]) {      		
        		std::swap(A[i], A[A[i] - 1]);
   			}
        }

        for (int i = 0; i < n; i++) {
        	if (A[i] != i + 1)	return i + 1;
        }
        return n + 1;
    }
};

int main(void) {
	Solution s;
	int A[] = {1, 0, 2, 1};
	cout << s.firstMissingPositive(A, sizeof(A) / sizeof(A[0])) << endl;
	return 0;
}