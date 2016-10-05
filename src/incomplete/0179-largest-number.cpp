#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

class Solution {
	public:
    	string largestNumber(vector<int>& nums);
};

vector<int> toVector(int num) {
	vector<int> result;

	if (num == 0) {
		result.push_back(0);

	} else {

		while (num) {
			int digit = num % 10;
			num = num / 10;
			result.push_back(digit);
		}
	}

	return result;
}

string toString(const vector<int> &digits) {

	string result;

	for(int i = digits.size()-1; i >= 0; i--) {

		int curr = digits[i];
		char curr_char = curr + '0';

		result.push_back(curr_char);
	}

	return result;
}

struct VectorSorter {
	bool operator()(vector<int> &val1, vector<int> &val2);
};

bool VectorSorter::operator()(vector<int> &val1, vector<int> &val2) {

	int length = val1.size();
		
	if (length > val2.size()) {
		length = val2.size();
	}

	auto itr1 = val1.rbegin();
	auto itr2 = val2.rbegin();

	for (int i=0 ; i < length; i++) {
	
		int digit1 = *itr1, digit2 = *itr2;
		itr1++; itr2++;

		if (digit1 == digit2) {
			continue;
		}

		if (digit1 < digit2) {
			return true;

		} else {
			return false;
		}
	}

	if (val1.size() > val2.size()) {

		while()
		return (*itr1) < (*val2.rbegin());

	} else if (val1.size() < val2.size() ) {
		return (*val1.rbegin()) < (*itr2);
	}

	return false;
}

string Solution::largestNumber(vector<int>& nums) {

	string result;
	vector<vector<int> > digit_nums;

	for(int i=0; i < nums.size(); i++) {
		digit_nums.push_back( toVector(nums[i]) );
	}

	sort(digit_nums.begin(), digit_nums.end(), VectorSorter());

	for (int i = digit_nums.size()-1; i >= 0; i--) {
		result.append( toString(digit_nums[i]) );
	}	

	return result;
}

int main(int argc, const char **argv) {

	Solution ans;
	string output;

	int arr1[] = {3, 30, 34, 5, 9};
	vector<int> vec1(arr1, arr1+5);
	output = ans.largestNumber(vec1);
	cout << output << endl;

	int arr2[] = {1, 20};
	vector<int> vec2(arr2, arr2+2);
	output = ans.largestNumber(vec2);
	cout << output << endl;

	int arr3[] = {128,12};
	vector<int> vec3(arr3, arr3+2);
	output = ans.largestNumber(vec3);
	cout << output << endl;

	int arr4[] = {12,121};
	vector<int> vec4(arr4, arr4+2);
	output = ans.largestNumber(vec4);
	cout << output << endl;

}
