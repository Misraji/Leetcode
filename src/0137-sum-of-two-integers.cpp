#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <utility>
using std::pair;
using std::make_pair;

class Solution {
	public:
    	int getSum(int a, int b);

	private:
		pair<bool, bool> bitSum(bool a, bool b, bool c);

};

// c == carry
pair<bool, bool> Solution::bitSum(bool a, bool b, bool c) {
	
	bool sum = false;
	bool carry = false;

	sum = a ^ b;
	carry = a && b;

	if (carry) {
		// sum == 0 (since max(a + b) = (0,1)
		// carry remains the same;
		sum = c;

	} else {
		// Add c to sum;
		sum = sum ^ c;
		carry = sum & c;
	}

	return pair<bool, bool>(sum, carry);
}

int Solution::getSum(int a, int b) {

	int result = 0;	
	bool val1 = false, val2 = false , c = false, sum = false;
	pair<bool, bool> tmp;

	int i = 0;

	while (a || b) {
		val1 = a & 1;
		val2 = b & 1;

		a = a >> 1;
		b = b >> 1;

		tmp = bitSum(val1, val2, c);
		sum = tmp.first;
		c = tmp.second;

		result |= (sum << i);
		i++;
	}

	result |= (c << i);
	return result;
}

int main(int argc, const char **argv) {

	Solution adder;

	cout << "1 + 2 = " << adder.getSum(1,2) << endl;
	cout << "5 + 10 = " << adder.getSum(5,10) << endl;
}
