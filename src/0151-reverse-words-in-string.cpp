#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Solution {
	public:
		void reverseWords(string &s);

	private:
		void reverseString(string &s, int start, int end);
};

void Solution::reverseString(string &s, int start, int end) {

	int i = start;
	int j = end;
	char tmp;

	for ( ; i < j; i++, j--) {
		tmp = s[i]; 
		s[i] = s[j];
		s[j] = tmp;
	}
}

void Solution::reverseWords(string &s) {
	if (s.length() == 0) {
		return;
	}

	reverseString(s, 0, (s.length()-1));

	int start = 0, end = 0;

	while(1) {
		while ((end < s.length()) && (s[end] == ' ')) {
			end++;
		}

		start = end;

		while ((end < s.length()) && (s[end] != ' ')) {
			end++;
		}

		if (start == end) {
			break;
		}

		reverseString(s, start, end-1);
	}
}

int main(int argc, const char **argv) {

	Solution tmp;
	string output("Hello world");

	tmp.reverseWords(output);
	cout << "reverse(output) = " << output << endl;
}
