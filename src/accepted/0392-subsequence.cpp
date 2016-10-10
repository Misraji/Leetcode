#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
    	bool isSubsequence(string s, string t);
};

bool Solution::isSubsequence(string s, string t) {

	auto s_itr = s.begin();
	auto t_itr = t.begin();

	while ( (s_itr != s.end()) && (t_itr != t.end())) {
		if (*s_itr == *t_itr) {
			++s_itr;
		}
		++t_itr;
	}
	
	return (s_itr == s.end());
}

int main(int argc, const char **argv) {

	Solution ans;

	cout << "isSubsequence(abc, ahbgdc) = " << ans.isSubsequence("abc", "ahbgdc")<< endl;
	cout << "isSubsequence(axc, ahbgdc) = " << ans.isSubsequence("axc", "ahbgdc")<< endl;
}
