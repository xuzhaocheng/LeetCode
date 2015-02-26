#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void generateParenthes(vector<string> &strs, string str, int left, int right) {
    	if (left == 0 && right == 0) {
    		strs.push_back(str);
    		return;
    	}

		if (left > right)	return;

    	if (left > 0) {
    		generateParenthes(strs, str + "(", left - 1, right);
    	}

    	if (right > 0) {
    		generateParenthes(strs, str + ")", left, right - 1);
    	}
    }

    vector<string> generateParenthesis(int n) {
		vector<string> strs;
		if (n == 0) {
			strs.push_back("");
			return strs;
		}

        string str = "(";
        generateParenthes(strs, str, n - 1, n);
        return strs;
    }
};

int main(void) {
	Solution s;
	vector<string> strs = s.generateParenthesis(3);
	for (int i = 0; i < strs.size(); i++) {
		cout << strs[i] << endl;
	}
	return 0;
}