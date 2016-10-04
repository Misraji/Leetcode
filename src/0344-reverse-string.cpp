#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

class Solution {
	public:
    	string reverseString(string s);
	private:
};

string Solution::reverseString(string s) {
	
	string result;
	for (string::reverse_iterator rit = s.rbegin() ; rit != s.rend(); rit++) {
		result.push_back(*rit);
	}
	return result;	
}

int main(int argc, const char **argv) {

	Solution reverser;
	string output("Hello");

	cout << "reverse(Hello) = " << reverser.reverseString(output) << endl;
	cout << "reverse(string("")) = " << reverser.reverseString(string("")) << endl;
}
