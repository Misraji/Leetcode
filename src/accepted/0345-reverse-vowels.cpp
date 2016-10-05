#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <set>
using std::set;

class Solution {
	public:
		Solution() {
			vowels.insert('a'); vowels.insert('A');
			vowels.insert('e'); vowels.insert('E');
			vowels.insert('i'); vowels.insert('I');
			vowels.insert('o'); vowels.insert('O');
			vowels.insert('u'); vowels.insert('U');
		}

    	string reverseVowels(string s);
        
	private:
		bool isVowel(char c);
		set<char> vowels;
};

bool Solution::isVowel(char c) {
	return (vowels.count(c) > 0);
}

string Solution::reverseVowels(string s) {
	
	string result;
	int end = (s.length() - 1);

	result = s;
	for(int i=0; i < result.length() ; i++) {
	
		if ( isVowel( result[i] ) ) {

			// current character is a vowel. replace it.
			// search for the last vowel in original string.
			while( !isVowel( s[end] ) ) {
				end--;
			}

			result[i] = s[end--];
		} 
	}

	return result;
}

int main(int argc, const char **argv) {

	Solution ans;

	cout << "reverseVowels(hello) = " << ans.reverseVowels("hello") << endl;
	cout << "reverseVowels(leetcode) = " << ans.reverseVowels("leetcode") << endl;
}
