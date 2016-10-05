#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <utility>
using std::pair;
using std::make_pair;

#include <algorithm>
using std::sort;

class Solution {
	public:
    	vector<pair<int, int> > reconstructQueue(vector<pair<int, int> > &people);
};

class HeightSorter {
	public:
		bool operator()(const pair<int, int> &val1, const pair<int, int> &val2) {
			if (val1.second < val2.second) {
				return true;

			} else if (val1.second == val2.second) {
				return (val1.first < val2.first);

			}

			return false;
		}
};

vector<pair<int, int> > Solution::reconstructQueue(vector<pair<int, int> > &people) {
	vector<pair<int, int> > result(people.begin(), people.end());

	sort(result.begin(), result.end(), HeightSorter());
	return result;
}

std::ostream& operator<<(std::ostream &out, const pair<int, int> &input) {
	out << "[" << input.first << ", " << input.second << "]";
	return out;
}

int main(int argc, const char **argv) {

	// Input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
	// Output: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
	
	Solution ans;
	vector<pair<int, int> > input;
	vector<pair<int, int> > output;

	input.push_back(make_pair(7,0));
	input.push_back(make_pair(4,4));
	input.push_back(make_pair(7,1));
	input.push_back(make_pair(5,0));
	input.push_back(make_pair(6,1));
	input.push_back(make_pair(5,2));

	output = ans.reconstructQueue(input);
	for (auto itr = output.begin(); itr != output.end(); itr++ ) {
		cout << *itr << ",";
	}
	cout << endl;
}
