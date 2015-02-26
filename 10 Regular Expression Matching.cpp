// 10 Regular Expression Matching.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string.h>

using namespace std;

// DP解法 https://oj.leetcode.com/discuss/19536/sharing-my-44ms-dp-code-o-mn-time-and-o-n-space

// 递归，遍历所有“*”的情况
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
		int i =  strlen(s) - 1, j = strlen(p) - 1;
		while(i >= 0 && j >= 0) {
			if (p[j] == '.') {
				j--;
				i--;
			} else if (p[j] == s[i]) {
				j--;
				i--;
			} else if (p[j] == '*') {
				if (j - 1 >= 0) {
					if (p[j-1] == '.' || p[j-1] == s[i]) {
						if (j - 2 >= 0) {
							char *ss = (char *)malloc(sizeof(char) * (i + 2));
							char *pp = (char *)malloc(sizeof(char) * (j));
							strncpy(ss, s, i + 1);
							strncpy(pp, p, j - 1);
							ss[i+1] = '\0';
							pp[j-1] = '\0';
							if (isMatch(ss, pp)) {
								return true;
							}
							free(ss);
							free(pp);
						}
						i--;
						if (i < 0)	j -= 2;
					} else {
						j -= 2;
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
		}

		if (i >= 0) {
			return false;
		}
		while(j >= 0) {
			if (p[j] == '*'&& j - 1 >= 0 && p[j-1] != '*') j -= 2;
			else {
				return false;
			}
		}

		return true;
    }
};


void test(const char *s, const char *p) {
	Solution solution;
	cout << "s: " << s << ", p: "<< p << " "; 
	if (solution.isMatch(s, p))
		cout << "Yes";
	else 
		cout << "No";
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	test("aaa", "aa");
	test("aa", "aa");
	test("aa", "a");
	test("aaa", "ab*a*c*a");
	test("aa", "a*");
	test("aa", ".*");
	test("ab", ".*");
	test("aab", "c*a*b");
	test("baaaaaab", "bab*a*aaa*b*ab");
	return 0;
}

