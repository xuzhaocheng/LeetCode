#include <iostream>
#include <vector>
#include <string>
#include "stdlib.h"
#include "string.h"

using namespace std;

/*
** 递归
** OJ 超时
*/
/*
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
    	string p_str;
    	for (int i = 0; i < strlen(p); i++) {
       		if (p_str.empty() || p[i] != '*' || p_str[p_str.size() - 1] !=  p[i])
       			p_str.push_back(p[i]);
    	}

    	char *pp = new char [p_str.size() + 1];
    	for (int i = 0; i < p_str.size(); i++) {
    		pp[i] = p_str[i];
    	}
    	pp[p_str.size()] = '\0';
    	return match(s, pp, 0, 0); 
    }

    bool match(const char *s, const char *p, int i, int j) {
    	cout << "i:" << i << " j:" << j << endl;
    	if (i == strlen(s) && j == strlen(p)) 
   			return true;
   		
    	if (i == strlen(s)) {
    		while (j < strlen(p)) {
    			if (p[j] != '*')	return false;
    			j++;
    		}
    		return true;
    	}
    	if (j == strlen(p) && i < strlen(s))	return false;

    	if (s[i] == p[j] || p[j] == '?')
    		return match(s, p, i+1, j+1);
    	else if (p[j] == '*') {
    		int total = 0;
    		for (int k = j+1; k < (int)strlen(p); k++)
    			if (p[k] != '*')	total++;

    		for (int k = i; k <= (int)strlen(s) - total; k++) {
    			if (match(s, p, k, j+1))
    				return true;
    		}

    		return false;
    	} else {
    		return false;
    	}
    }
};
*/


/**
* dp，可优化成一维数组
* b[i+1][j+1]表示s[0..i]是否匹配p[0..j]
* 递推公式
* 1) p[j] != '*'
* 	 b[i+1][j+1] = b[i][j] || (p[j] == '?' || p[j] == s[i])
* 2) p[j] == '*'
*	 b[i+1][j+1] = b[i+1][j] || b[i][j+1]
**/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
  		int i, j;
  		int m = strlen(s);
  		int n = strlen(p);
  		if(m>30000) return false;

  		vector<vector<bool> > b(m+1, vector<bool>(n+1, false));
  		b[0][0] = true;
  		for (i = 0; i < m; i++) 
  			b[i+1][0] = false;

  		for (j = 0; j < n; j++) {
	  		b[0][j+1] = '*' == p[j] && b[0][j];
  		}

  		for (i = 0; i < m; i++) {
  			for (j = 0; j < n; j++) {
  				if (p[j] == '*') {
  					b[i+1][j+1] = j==0 || b[i][j];
  				} else {
  					b[i+1][j+1] = b[i][j] && (p[j] == '?' || p[j] == s[i]);
  				}
  			}
  		}

  		return b[m][n];      
    }
};


int main(void) {
	Solution s;
/*
	if (s.isMatch("aa", "a"))
		cout << "WA: aa, a" << endl;
	if (!s.isMatch("aa", "aa"))
		cout << "WA: aa, aa" << endl;
	if (s.isMatch("aaa", "aa"))
		cout << "WA: aaa, aa" << endl;
	if (!s.isMatch("aa", "*")) 
		cout << "WA: aa, *" << endl;
	if (!s.isMatch("aa", "a*"))
		cout << "WA: aa, a*" << endl;
	if (!s.isMatch("ab", "?*"))
		cout << "WA: ab, ?*" << endl;
	if (s.isMatch("aab", "c*a*b*"))
		cout << "WA: aab, c*a*b*" << endl;
	if (!s.isMatch("", "*"))
		cout << "WA: null, *" << endl;
	if (s.isMatch("aaa", ""))
		cout << "WA: aaa, null" << endl;
	if (!s.isMatch("aaa", "**"))
		cout << "WA: aaa, **" << endl;
	if (!s.isMatch("aaa", "*a"))
		cout << "WA: aaa, *a" << endl;
	
	if (s.isMatch("b", "*?*?"))
		cout << "WA: b, *?*?" << endl;

	if (s.isMatch("aaabbbaabaaaaaaaaaaa", "a*b"))
		cout << "WA: aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba, a*******b" << endl;
	cout << "All Tests Done" << endl;*/

	s.isMatch("abefcdgiescdfimde", "ab*cd?i*de");
	return 0;
}