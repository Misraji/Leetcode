#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cmath>

class Solution {
	public:
    	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
};

bool withinRange(int a, int b, int t) {
	
	int64_t diff = (a-b);

	if (diff <= INT_MIN) {
		return false;
	}

	return (std::abs(diff) <= t);
}

bool Solution::containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

	int i = 0;

	for (; (i+k) < nums.size(); i++) {
		for(int j = i+1; j <= (i+k) ; j++) {
			if ( withinRange(nums[i], nums[j], t)) {
				return true;
			}
		}
	}

	for (; i < nums.size(); i++) {
		for(int j = i+1; j < nums.size() ; j++) {
			if ( withinRange(nums[i], nums[j], t)) {
				return true;
			}
		}
	}

	return false;
}

int main(int argc, const char **argv) {

	vector<int> values;
	values.push_back(-1);
	values.push_back(2147483647);

	Solution tmp;
	cout << tmp.containsNearbyAlmostDuplicate(values, 1, 2147483647) << endl;
}
