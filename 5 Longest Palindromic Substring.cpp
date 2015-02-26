// 5 Longest Palindromic Substring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>

using namespace std;

/*
class Solution {
public:
    string longestPalindrome(string s) {
		int maxLength = 0;
		int beginIndex = 0;
		for (int i = 0; i < s.length() && s.length() - i > maxLength; i++) {
			for (int j = i + 1; j < s.length(); j++) {
				if (j - i + 1 > maxLength) {
					if (isPalindromic(s.substr(i, j-i+1))) {
						maxLength = j - i + 1;
						beginIndex = i;
					}
				}
			}
		}
		if (maxLength == 0) return s.substr(0, 1);
		return s.substr(beginIndex, maxLength);
    }

	bool isPalindromic(string s) {
		int i = 0, j = s.length() - 1;
		while (i <= j) {
			if(s[i] != s[j])	return false;
			i++;
			j--;
		}
		return true;
	}
};
*/

// http://www.felix021.com/blog/read.php?2040 O(n)算法

class Solution {
public:
    string longestPalindrome(string s) {
		int maxLength = 0;
		int beginIndex = 0;
		
		for (int k = 1; k < s.length(); k++) {
			int i = k - 1, j = k + 1;
			while (i >= 0 && j < s.length() && s[i] == s[j]) {
				i--;
				j++;
			}

			if (j - i - 1> maxLength) {
				maxLength = j - i - 1;
				beginIndex = i + 1;
			}
		}

		for (int k = 0; k < s.length() - 1; k++) {
			if (s[k] == s[k+1]) {
				if (maxLength < 2) {
					maxLength = 2;
					beginIndex = k;
				}
				
				int i = k - 1, j = k + 2;
				while (i >= 0 && j < s.length() && s[i] == s[j]) {
					i--; 
					j++;
				}

				if (j - i - 1 > maxLength) {
					maxLength = j - i - 1;
					beginIndex = i + 1;
				}
			}
		}

		if (maxLength == 0) return s.substr(beginIndex, 1);
		return s.substr(beginIndex, maxLength);
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	cout << solution.longestPalindrome("abcd") << endl;
	return 0;
}

