#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
		bool isMatch(string s, string p);

	private:
		bool isMatch(string s, string p, int s_start, int p_start);
};

bool Solution::isMatch(string s, string p, int s_start, int p_start) {

	// All argument checks.
	
	// End of recursion. String s satisfies pattern p
	if ((s_start >= s.size()) && (p_start >= p.size()) ) {
		return true;
	}	

	// Only one of the strings has been exhausted. Return false.
	if ((s_start >= s.size())) {

		int p_new = p_start;
		
		// Ignore all the '*' wild-cards.
		for ( ; p_new < p.size(); ++p_new) {
			if (p[p_new] != '*') {
				break;
			}
		}

		return (p_new == p.size());
	}

	// Pattern string has been exhausted. No change.
	if (p_start >= p.size()) {
		return false;
	}

	char p_char = p[p_start], s_char = s[s_start];

	if (p_char == '?') {
		return isMatch(s, p, s_start+1, p_start+1);

	} if (p_char == '*') {

		for (int i = 0; i + s_start <= s.size(); ++i) {
		
			// Move the pattern ahead by 1. 
			// Do not move the string head;
			if (isMatch(s, p, (s_start + i), (p_start+1))) {
				return true; 
			}
		}

		// No pattern works.
		return false;
	}

	// Not a wild-card. Do straight comparison.
	return ((s_char == p_char) && isMatch(s, p, (s_start + 1), (p_start+1)) );

}

bool Solution::isMatch(string s, string p) {

	// All argument checks.

	// All variable initializations.
	
	return isMatch(s, p, 0, 0);
}

int main(int argc, const char **argv) {

	Solution ans;
	bool result;

	result = ans.isMatch("aa","a");
	cout << "isMatch('aa', 'a' ) = " << result << endl; 

	result = ans.isMatch("aa","aa");
	cout << "isMatch('aa', 'aa' ) = " << result << endl; 

	result = ans.isMatch("aaa","aa");
	cout << "isMatch('aaa', 'aa' ) = " << result << endl; 

	result = ans.isMatch("aa","*");
	cout << "isMatch('aa', '*' ) = " << result << endl; 

	result = ans.isMatch("aa","a*");
	cout << "isMatch('aa', 'a*' ) = " << result << endl; 

	result = ans.isMatch("ab","?*");
	cout << "isMatch('ab', '?*' ) = " << result << endl; 

	result = ans.isMatch("aab","c*a*b");
	cout << "isMatch('aab', 'c*a*b' ) = " << result << endl; 

	result = ans.isMatch("","*");
	cout << "isMatch('', '*' ) = " << result << endl; 

	result = ans.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b");
	cout << "isMatch('aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaabar', 'a*******b')" << result << endl;

}
