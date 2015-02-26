#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	stack<char> parentheses;

    	for (int i = 0; i < s.length(); i++) {
    		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
    			parentheses.push(s[i]);
    		} else {
    			if (parentheses.size() == 0) return false;
    			char c = parentheses.top();
    			parentheses.pop();
    			if (s[i] == ')') {
    				if (c != '(')	return false;
    			} else if (s[i] == ']') {
    				if (c != '[')	return false;
    			} else if (s[i] == '}') {
    				if (c != '{')	return false;
    			}
    		}
    	}

    	if (parentheses.size() == 0)	return true;
    	return false;
    }
};

int main(void) {
	Solution s;
	string str;
	cin >> str;
	if (s.isValid(str))
		cout << "Yes";
	else 
		cout << "No";
	cout << endl;
	return 0;
}

