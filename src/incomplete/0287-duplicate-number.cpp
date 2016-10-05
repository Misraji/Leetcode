#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
    	int findDuplicate(vector<int>& nums);

    private: 
};

int Solution::findDuplicate(vector<int>& nums) {

	int n = nums.size();
	int ideal_sum = 0;
	int actual_sum = 0;

	for (int i=0; i < nums.size(); i++) {
		actual_sum += nums[i];
	}

	// preventing overflow on multiplication.
	if (n % 2) {
		ideal_sum = ((n+1)/2) * n;

	} else {
		ideal_sum = (n/2) * (n+1);
	}

	
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");
	cout << output << endl;
}
