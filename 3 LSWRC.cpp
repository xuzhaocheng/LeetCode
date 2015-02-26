// 3 LSWRC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <hash_set>

using namespace std;
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int maxLength = 0;
		for (int i = 0; i < s.length(); i++) {
			int length = 1;
			hash_set<char> hashSet;
			hashSet.insert(s[i]);
			for (int j = i + 1; j < s.length(); j++) {
				if (hashSet.find(s[j]) == hashSet.end()) {
					hashSet.insert(s[j]);
					length++;
				} else {
					break;
				}
			}

			if (length > maxLength) {
				maxLength = length;
			}
		}
		return maxLength;
    }
};*/

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int maxLength = 0;
		int hashSet[128];
		int i = 0;
		while(i < s.length()) {
			if (s.length() - i <= maxLength)	 break; 
			int length = 1;
			memset(hashSet, 0, sizeof(hashSet));
			hashSet[s[i]] = 1;
			for (int j = i + 1; j < s.length(); j++) {
				if (hashSet[s[j]] == 0) {
					hashSet[s[j]] = 1;
					length++;
				} else {
					int index = s.find(s[j], i);
					i = index;
					break;
				}
			}

			if (length > maxLength) {
				maxLength = length;
			}
			i++;
		}
		return maxLength;
    }
};

*/


// 用一个数组维护每个字符上一次在字符串中出现的位置。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int lastIndice[128];
		memset(lastIndice, -1, sizeof(lastIndice));
		int length = 0;
		int startIndex = 0;
		int maxLength = 0;
		for (int i = 0; i < s.length(); i++) {
			if (lastIndice[s[i]] >= startIndex) {
				startIndex = lastIndice[s[i]] + 1;
				length = i - startIndex;
			}
			lastIndice[s[i]] = i;
			length ++;
			if (length > maxLength) {
				maxLength = length;	
			};
		}
		return maxLength;
    }
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;

	//cout << (int)'z' << endl;
	return 0;
}

