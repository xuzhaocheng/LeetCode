#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) return;
        int i = num.size() - 1;
        int max = num[i];
        i--;
        while (i >= 0) {
        	if (num[i] >= max)	{
        		max = num[i];
        		i--;
        	}
        	else break;
        }

        if (i != -1) {
        	int j;
        	if (i + 1 < num.size() - 1)
	        	j = binarySearch(num, i+1, num.size()-1, num[i]);
        	else
        		j = i+1;	
  
        	swap(num[i], num[j]);
        	std::sort(num.begin() + i + 1, num.end());
        } else {
        	std::reverse(num.begin(), num.end());
        }

    }

    int binarySearch(vector<int> &num, int left, int right, int target) {
    	int mid;
    	while (left <= right) {
    		mid = (left + right) >> 1;
    		if (num[mid] > target) {
    			left = mid + 1;
    		} else if (num[mid] < target) {
    			right = mid - 1;
    		} else {
    			int i = mid - 1;
    			while (num[i] == num[mid] && i >= 0) i--;
    			return i;
    		}
    	}

    	if (left > mid)	return mid;
    	if (right < mid) return right;
    }

};

int main(void) {
	Solution s;
	
	// int n[] = {2, 2, 7, 5, 4, 3, 2, 2, 1};
	int n[] = {1, 3, 2};
	vector<int> num;
	for (int i = 0; i < sizeof(n) / sizeof(n[0]); i++) {
		num.push_back(n[i]);
	}
	
	s.nextPermutation(num);

	for (int i = 0; i < num.size(); i++)
		cout << num[i] << " ";
	cout << endl;
	return 0;
}