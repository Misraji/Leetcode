#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
    	vector<int> countBits(int num);
};

bool isPowerOfTwo(int x) {
	// This expression checks if x has only one bit set.
	return ((x & (x-1)) == 0);
}

vector<int> Solution::countBits(int num) {

	vector<int> result(num+1);
	int latest_power = 0;

	// base cases
	result[0] = 0;
	result[1] = 1;

	for(int i=2; i <= num; i++) {

		if (isPowerOfTwo(i)) {
			result[i] = 1;
			latest_power = i;

		} else {
			int diff = i - latest_power;
			// Number of bits = 1 (for latest-power) + bit representation of
			// rest.
			result[i] = 1 + result[diff];
		}
	}

	return result;
}

int main(int argc, const char **argv) {

	Solution ans;

	// output: [0,1,1,2,1,2]
	vector<int> output = ans.countBits(5);

	cout << "[ " ;
	for (int i=0; i < output.size(); i++ ) {
		cout << output[i] << ", " << endl;
	}
	cout << " ]" << endl;
}
