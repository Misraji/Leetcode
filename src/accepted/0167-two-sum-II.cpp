#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <utility>
using std::pair;
using std::make_pair;

class Solution {
	public:
    	vector<int> twoSum(vector<int>& numbers, int target);
};

vector<int> Solution::twoSum(vector<int>& numbers, int target) {
	vector<int> result;
	// TODO: Should we use a multi-map;
	map<int, int> num_set;

	for(int i = 0; i != numbers.size(); ++i) {
		num_set[numbers[i]] = i;
	}

	for(int i = 0; i != numbers.size(); ++i) {
		
		int map_target = target - numbers[i];
		if (num_set.count(map_target) > 0) {
			result.push_back((i+1));
			result.push_back((num_set[map_target]+1));	
			break;
		}
	}

	return result;	
}

int main(int argc, const char **argv) {
	
	Solution ans;

	int arr1[] = {2, 7, 11, 15};
	vector<int> vec1(arr1, (arr1+4));

	vector<int> result = ans.twoSum(vec1, 9);
	cout << "[ " << result[0] << ", " << result[1] << " ]" << endl;

}
