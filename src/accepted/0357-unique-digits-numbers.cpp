#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

class Solution {
	public:
    	int countNumbersWithUniqueDigits(int n);

	private:
		int countNumbersForSize(int n);
};

int Solution::countNumbersForSize(int n) {
	// All argument checks
	// For digit size > 10, atleast one digit has to be repeated.
	if (n > 10) {
		return 0;
	}

	// This is a special case where 0 is allowed as the first digit.
	if (n == 1) {
		return 10;
	}

	// All variable initialializations.
	const int NUM_DIGITS = 10;
	int num_digits = min(10, n); 

	int curr_opts = 9;

	for (int j=2; j <= num_digits; j++) {
		curr_opts *= (NUM_DIGITS - j + 1);
	}

	return curr_opts;
}

int Solution::countNumbersWithUniqueDigits(int n) {
	// All argument checks
	if (n == 0) {
	    // HUH?? This seems to be an ideosyncracy of leet-code.
	    return 1;
	}
	
	// All variable initializations
	int result = 0;

	for(int curr = 1; curr <= n; curr++) {
		result += countNumbersForSize(curr);	
	}
	
	return result;
}

int main(int argc, const char **argv) {

	Solution ans;

	cout << "func(2) = " << ans.countNumbersWithUniqueDigits(2) << endl;
}
