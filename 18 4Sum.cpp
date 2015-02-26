#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		
		std::sort(num.begin(), num.end());
		vector<vector<int> > quadruplets;

		for (int i = 0; i < num.size(); i++) {
			if (i > 0 && num[i] == num[i-1])	continue;
			for (int j = i + 1; j < num.size(); j++) {
				if (j > i + 1 && num[j] == num[j-1]) continue;
				int twoSum = num[i] + num[j];
				int m = j + 1, n = num.size() - 1;
				while (m < n) {
					if (twoSum + num[m] + num[n] > target) 
						n--;
					else if (twoSum + num[m] + num[n] < target)
						m++;
					else {
						vector<int> quadruplet;
						quadruplet.push_back(num[i]);
						quadruplet.push_back(num[j]);
						quadruplet.push_back(num[m]);
						quadruplet.push_back(num[n]);
						quadruplets.push_back(quadruplet);
						n--;
						m++;
						while(m < n && (num[n] == num[n+1] || num[m] == num[m-1])) {
							if (num[n] == num[n+1])	n--;
							if (num[m] == num[m-1]) m++;
						}
					}
				}
			}
		}

		return quadruplets;
    }
};

int main(void) {
	Solution s;

	// int n[] = {1, 0, -1, 0, -2, 2};
	int n[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	vector<int> num;

	for (int i = 0; i < sizeof(n) / sizeof(n[0]); ++i) {
		num.push_back(n[i]);
	}

	vector<vector<int> > vec = s.fourSum(num, 0);

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}