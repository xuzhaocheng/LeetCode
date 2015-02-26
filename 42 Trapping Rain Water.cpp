#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
    	if (n <= 2)	return 0;
    	int i;
    	int sum = 0;
    	for (i = 0; i < n && A[i] == 0; i++);
    	while (A[n-1] == 0 && n >= 0) n--;

    	vector<int> lefts;
    	lefts.push_back(i);
    	for (int j = i+1; j < n - 1; j++) {
    		if (A[j] > A[j+1])
    			lefts.push_back(j); 
    	}

    	if (n-1 != i)
	    	lefts.push_back(n-1);

    	for (int j = 1; j < lefts.size() - 1; j++) {
    		int l, r;
    		for (r = j+1; r < lefts.size() && A[lefts[r]] <= A[lefts[j]]; r++);
    		for (l = j-1; l >= 0 && A[lefts[l]] <= A[lefts[j]]; l--);

    		if (r < lefts.size() && l >= 0) {
    			lefts.erase(lefts.begin() + j);
    			j--;
    		}
    	}

    	for (i = 0; i < lefts.size() - 1; i++) {
    		int height = min(A[lefts[i]], A[lefts[i+1]]);
    		sum += height * (lefts[i+1] - lefts[i] - 1);
    		for (int j = lefts[i] + 1; j < lefts[i+1]; j++)
    			sum -= A[j] > height ? height : A[j];
    	}

    	return sum > 0 ? sum : 0;
    }
};


/*
class Solution {
public:
    int trap(int A[], int n) {
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};

*/
int main(void) {
	Solution s;
	int A[] = 
	// {2, 0, 2};//2
	// {5,2,1,2,1,5};//14
	// {1};//0
	// {0, 2, 0};//0
	// {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};//83
	// {4,9,4,5,3,2}; //1
	cout << s.trap(A, sizeof(A) / sizeof(A[0])) << endl;
	return 0;
}