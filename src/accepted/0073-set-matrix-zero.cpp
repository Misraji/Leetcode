#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
    	void setZeroes(vector< vector<int> > &matrix);

	private:
};

void Solution::setZeroes(vector< vector<int> > &matrix) {
	
	int num_rows = matrix.size();
	int num_columns = matrix[0].size();

	vector<bool> rows(num_rows, false);
	vector<bool> columns(num_columns, false);

	for (int i=0; i < num_rows; i++) {
		for (int j=0; j < num_columns; j++) {
			if (matrix[i][j] == 0) {
				rows[i] = true;
				columns[j] = true;
			}	
		}
	}

	for (int i=0; i < num_rows; i++) {
		for (int j=0; j < num_columns; j++) {
			if (rows[i] || columns[j]) {
				matrix[i][j] = 0;
			}
		}
	}

}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
