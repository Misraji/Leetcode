#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <climits>

class Solution {
	public:
		int minPathSum(vector<vector<int> > &grid);

	private:
		int minPathSum(vector<vector<int> > &grid, int i, int j);
};


int Solution::minPathSum(vector<vector<int> > &grid, int i, int j) {

	// Reached our path.
	if (	(i == (grid.size() - 1)) && 
			(j == (grid[0].size() - 1))
		) {
		return grid[i][j];
	}

	// Argument check.
	if ((i >= grid.size()) && (j >= grid[0].size()) ) {
		throw 0;
	}

	int result = INT_MAX;
	int tmp_result;

	if (i < (grid.size() - 1)) {
		result = minPathSum(grid, (i+1), j) + grid[i][j];
	}

	if (j < (grid[0].size() - 1)) {
		tmp_result = minPathSum(grid, i, (j+1)) + grid[i][j];
		result = (result > tmp_result) ? tmp_result : result;
	}

	return result;
}

int Solution::minPathSum(vector<vector<int> > &grid) {

	// All argument checks.
	if (grid.empty() || grid[0].empty()) {
		return 0;
	}

	return minPathSum(grid, 0, 0);
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
