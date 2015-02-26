#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "stdlib.h"

using namespace std;

/*
** 将每个单词按字母升序排序后作为hash key
** key相同的则为同一个anagrams
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
    	unordered_map<string, vector<string> > map;
        for (int i = 0; i < strs.size(); i++) {
        	string tmp = strs[i];
        	std::sort(tmp.begin(), tmp.end());
        	if (map.find(tmp) != map.end()) {
        		map[tmp].push_back(strs[i]);
        	} else {
        		vector<string> ss;
        		ss.push_back(strs[i]);
        		map[tmp] = ss;
        	}
        }

        vector<string> ret;
        unordered_map<string, vector<string> >::iterator it;
        for (it = map.begin(); it != map.end(); it++) {
        	if (it->second.size() > 1)
        		ret.insert(ret.end(), it->second.begin(), it->second.end());
        }

        return ret;
    }
};

int main(void) {
	Solution s;
	vector<string> strs;
	string a = "rewa";
	strs.push_back(a);
	a = "eawr";
	strs.push_back(a);
	a = "rwae";
	strs.push_back(a);
	a = "poap";
	strs.push_back(a);
	a = "oeka";
	strs.push_back(a);

	vector<string> res = s.anagrams(strs);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}