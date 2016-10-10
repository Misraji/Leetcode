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
		void minPathSum(vector<vector<int> > &grid, int i, int j, int path_sum, int &min_path);
};


void Solution::minPathSum(vector<vector<int> > &grid, int i, int j, int path_sum, int &min_path) {

	if ((i == (grid.size()-1)) && 
		(j == (grid[0].size()-1)) 
	) {
		int new_path_sum = path_sum + grid[i][j];
		min_path = (new_path_sum < min_path) ? new_path_sum : min_path;
		return;
	}

	// Argument check.
	if ((i >= grid.size()) && (j >= grid[0].size()) ) {
		throw 0;
	}

	int new_path_sum = path_sum + grid[i][j];

	// Check if we should continue down our current path?
	if (new_path_sum > min_path) {
		return;
	}

	if (i < (grid.size() - 1)) {
		minPathSum(grid, (i+1), j, new_path_sum, min_path);
	}

	if (j < (grid[0].size() - 1)) {
		minPathSum(grid, i, (j+1), new_path_sum, min_path);
	}
}

int Solution::minPathSum(vector<vector<int> > &grid) {

	// All argument checks.
	if (grid.empty() || grid[0].empty()) {
		return 0;
	}

	int result = INT_MAX;
	minPathSum(grid, 0, 0, 0, result);

	return result;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
