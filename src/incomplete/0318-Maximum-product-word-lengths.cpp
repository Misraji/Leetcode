#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <bitset>
using std::bitset;

static const int NUM_CHARS = 26;

class Solution {
	public:
    	int maxProduct(vector<string>& words);
};

bool shareChars(bitset<NUM_CHARS> &char_map, const string &word2) {

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
	vector<int> word_size(words.size());
	vector<bitset<NUM_CHARS> > word_char_map(words.size());

	// Precomputing size and character-sets data for each word.
	for (int i=0; i < words.size(); i++) {

		string &curr_word = words[i];
		bitset<NUM_CHARS> &curr_map = 	word_char_map[i];

		word_size[i] = curr_word.length();

		for(int j=0; j < curr_word.size(); j++) {
			int pos = curr_word[j] - 'a';
			curr_map.set(pos);
		}
	}

	for(int i=0 ; i < words.size(); i++) {

		bitset<NUM_CHARS> &curr_map = 	word_char_map[i];

		for(int j=i+1; j < words.size(); j++) {

			if (shareChars(curr_map, words[j]) == false) {
				int new_prod = word_size[i] * word_size[j] ;
				if (new_prod > product) {
					product = new_prod;
				}
			}
		}
	}

	return product;
}
 
int main(int argc, const char **argv) {

	Solution ans;

	const char *arr1[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	vector<string> vec1;
	for(int i = 0; i < 6; i++) {
		vec1.push_back( string(arr1[i]));
	}

	int result = ans.maxProduct(vec1);
	cout << result << endl;
}
