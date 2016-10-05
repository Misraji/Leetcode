#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <bitset>
using std::bitset;

class Solution {
	public:
    	int maxProduct(vector<string>& words);
};

bool shareChars(const string &word1, const string &word2) {
	const int NUM_CHARS = 26;
	bitset<NUM_CHARS> char_map;

	for(int i=0; i < word1.size(); i++) {
		int pos = word1[i] - 'a';
		char_map.set(pos);
	}

	for(int i=0; i < word2.size(); i++) {
		int pos = word2[i] - 'a';
		if (char_map.test(pos)) {
			return true;
		}
	}
	return false;
}

int Solution::maxProduct(vector<string>& words) {
	
	int product = 0;

	for(int i=0 ; i < words.size(); i++) {
		for(int j=i+1; j < words.size(); j++) {
			if (shareChars(words[i], words[j]) == false) {
				
				int new_prod = words[i].size() * words[j].size() ;
				if (new_prod > product) {
					product = new_prod;
				}
			}
		}
	}

	return product;
}
 
int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
