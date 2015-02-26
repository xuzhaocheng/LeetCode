#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
        	string newStr;
        	int cnt = 1;
        	char beginDigit = s[0];

        	for (int j = 1; j < s.length(); j++) {
        		if (s[j] == beginDigit) cnt++;
        		else {
        			newStr.push_back(cnt + '0');
        			newStr.push_back(beginDigit);
        			cnt = 1;
        			beginDigit = s[j];
        		}
        	}
        	newStr.push_back(cnt + '0');
			newStr.push_back(beginDigit);
        	s = newStr;
        }
	    return s;
    }
    
};

int main(void) {
	Solution s;
	cout << s.countAndSay(7) << endl;
	return 0;
}