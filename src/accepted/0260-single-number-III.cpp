#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

class Solution {
	public:
    	vector<int> singleNumber(vector<int>& nums);
};

vector<int> Solution::singleNumber(vector<int>& nums) {
	map<int,int> num_count;
	vector<int> result;

	for(auto itr = nums.begin(); itr != nums.end(); ++itr) {
		num_count[*itr]++;
	}

	for(auto itr = num_count.begin(); itr != num_count.end(); ++itr) {
		if (itr->second == 1) {
			result.push_back(itr->first);
		}
	}

	return result;
}

int main(int argc, const char **argv) {

	string output("Hello world!!!");

	cout << output << endl;
}
