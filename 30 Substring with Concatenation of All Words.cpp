#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "stdlib.h"

using namespace std;

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;

        if (S.size() <= 0 || L.size() <= 0) return ret;

        int word_len = L[0].length();
        map<string, int> word_counter;
        for (int i = 0; i < L.size(); i++) {
            word_counter[L[i]]++;
        }

        for (int i = 0; i < word_len; i++) {
            map<string, int> counter;
            int left = i, total = 0;
            for (int j = i; j <= ((int)S.length()) - word_len; j += word_len) {
                string str = S.substr(j, word_len);
                if (word_counter.count(str)) {
                    counter[str]++;
                    if (counter[str] > word_counter[str]) {
                        while (counter[str] > word_counter[str]) {
                            string word = S.substr(left, word_len);
                            counter[word]--;
                            if (counter[word] < word_counter[word]) total--;
                            left += word_len;
                        }
                    } else {
                        total++;
                    }

                    if (total == L.size()) {
                        ret.push_back(left);
                        counter[S.substr(left, word_len)]--;
                        left += word_len;
                        total--;
                    }
                } else {

                    left = j + word_len;
                    total = 0;
                    counter.clear();
                }
            }
        }

        return ret;

    }
};

int main(void) {
	Solution s;
	vector<string> L;
    L.push_back("mississippis");
    // L.push_back("the");
    // L.push_back("foo");
	vector<int> res = s.findSubstring("mississippi", L);
	for(vector<int>::iterator it = res.begin(); it != res.end(); it++) 
		cout << *it << " ";
	cout << endl;
	return 0;
}