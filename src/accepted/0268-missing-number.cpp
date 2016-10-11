#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

class Solution {
	public:
    	int missingNumber(vector<int>& nums);
};

int Solution::missingNumber(vector<int>& nums) {
	
	int full_xor = 0;
	int vec_xor = 0;

	for (int i =0; i < nums.size(); ++i){
		full_xor ^= i;
		vec_xor ^= nums[i];
	}

	// Range of elements == 0 .. n
	full_xor ^= nums.size();

	return (full_xor ^ vec_xor);
}

int main(int argc, const char **argv) {

	Solution ans;

	int arr[] = {0, 1, 3};
	int arr_len = (sizeof(arr) / sizeof(int));
	vector<int> vec(arr , (arr + arr_len));

	cout << "missing number = " << ans.missingNumber(vec) << endl;
}
