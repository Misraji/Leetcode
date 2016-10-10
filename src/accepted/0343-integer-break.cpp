#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
    	int integerBreak(int n);
};

int Solution::integerBreak(int n) {
	
	// All argument checks.
	if (n < 2) {
		// TODO: Throw runtime exception.
		return -1;
	}	

	// All variable initializations.
	vector<int> products((n+1), -1);

	products[0] = 0;
	products[1] = 0;

	for(int curr = 2; curr <= n; curr++) {

		int max_prod = 0;

		for (int k=1; (k <= curr/2) ; k++) {
			
			int tmp_prod = -1;
			int rem = (curr - k);

			tmp_prod = k * rem;
			max_prod = (tmp_prod > max_prod) ? tmp_prod : max_prod;

			tmp_prod = products[k] * rem;
			max_prod = (tmp_prod > max_prod) ? tmp_prod : max_prod;

			tmp_prod = k * products[rem];
			max_prod = (tmp_prod > max_prod) ? tmp_prod : max_prod;

			tmp_prod = products[k] * products[rem];
			max_prod = (tmp_prod > max_prod) ? tmp_prod : max_prod;
		}

		products[curr] = max_prod;
	}

	return products[n];
}

int main(int argc, const char **argv) {

	Solution ans;

	cout << "integerBreak(02) = " << ans.integerBreak(2) << endl;
	cout << "integerBreak(10) = " << ans.integerBreak(10) << endl;
}
