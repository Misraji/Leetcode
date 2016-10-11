#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
		int kthSmallest(vector<vector<int> >& matrix, int k);
};

int Solution::kthSmallest(vector<vector<int> >& matrix, int k) {

	// All argument checks
	
	// All initializations
	vector<int> counters(matrix.size(), 0);
	int result;

	// Adding guard element.
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].push_back(INT_MAX);
	}

	for(int i = 0; i < k; i++) {

		int min_element = INT_MAX;
		int min_index = -1;

		for(int j = 0; j < matrix.size(); j++) {

			if (matrix[j][counters[j]] < min_element) {
				min_index = j;
				min_element = matrix[j][counters[j]];
			}
		}

		counters[min_index]++;
		result = min_element;
	}
	
	// Removing guard element
	for (int i = 0; i < matrix.size(); i++) {
		matrix[i].pop_back();
	}

	return result;
}

int main(int argc, const char **argv) {

	Solution ans;
	int result;

	vector<int> row1, row2, row3;
	vector<vector<int> > matrix;

	row1.push_back(1); row1.push_back(5); row1.push_back(9);
	row2.push_back(10); row2.push_back(11); row2.push_back(13);
	row3.push_back(12); row3.push_back(13); row3.push_back(15);

	matrix.push_back(row1); matrix.push_back(row2); matrix.push_back(row3);

	result = ans.kthSmallest(matrix, 8);
	cout << "result = " << result << endl;
}
