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

vector<int> Solution::countBits(int num) {
	vector<int> result;

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
